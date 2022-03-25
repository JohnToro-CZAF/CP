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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

vvi edge;

void solve(){
    int n, k;
    cin >> n >> k;  
    vi dis(n, 0);
    vi color(n, -1);
    vi leaf;
    edge = vvi(n, vector<int>());
    map<int, vi> m;
    queue<int> q;
    forn(i, k){
        int x;
        cin >> x;
        --x;
        q.push(x);
        color[x] = x+3;
    }
    forn(i, n-1){
        int x, y;
        cin >> x >> y;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    q.push(0);
    color[0] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : edge[v]){
            if(color[u] > 1){
                if(edge[u].size() == 1){
                    m[u].push_back(color[v]);
                } else{
                    color[u] = color[];
                    q.push(u);
                }
            }
        }
    }
    
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(i == 0) continue;
        if(edge[i].size() == 1 && color[i] == 1){
            flag = true;
            break;
        }
    }
    cout << (flag?"YES":"NO") << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

