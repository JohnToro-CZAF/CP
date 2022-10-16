#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

vector<int> mt;
vector<bool> used;

bool try_kuhn(int v, vvi& adj) {
    if (used[v])
        return false;
    used[v] = true;
    for (int to : adj[v]) {
        if (mt[to] == -1 || try_kuhn(mt[to], adj)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

int finding_matching(vvi& adj, int k1, int k2){
    mt.assign(k2, -1);
    for(int v = 0; v < k1; v++){
        used.assign(k1, false);
        try_kuhn(v, adj);
    }
    int mx = 0;
    for(int i = 0; i < k2; i++){
        if(mt[i] != -1){
            mx++;
        }
    }
    return mx;
}

void solve(){
    int n;
    while(cin >> n){
        vector<vector<int>> adj(n, vi());
        vector<pii> v;
        vector<pii> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int k1 = 0, k2 = 0;
        map<int, int> ord;
        forn(i, n){
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
            if((x+y) % 2 == 0){
                ord[i] = k1;
            } else {
                ord[i] = k2;
            }
            k1 += (((x + y) % 2) == 0);
            k2 += (((x + y) % 2) == 1);
        }

        forn(i, n){
            forn(j, n){
                if(i != j){
                    for(auto dir : dirs){
                        if((v[i].first + v[i].second) % 2 == 0){
                            if(v[j].first == (v[i].first + dir.first) && v[j].second == (v[i].second + dir.second)){
                                adj[ord[i]].push_back(ord[j]);
                            }
                        }
                    }
                }
            }
        }
        cout << n - finding_matching(adj, k1, k2) << endl;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

