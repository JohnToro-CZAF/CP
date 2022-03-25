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

vector<int> parent, rang, siz;

void make_set(int v) {
    parent[v] = v;
    rang[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rang[a] < rang[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
        if (rang[a] == rang[b])
            rang[a]++;
    } else{
        return;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    vii req;
    forn(i, m){
        int x, y; cin >> x >> y;
        x--; y--;
        req.push_back(make_pair(x, y));
    }
    forn(i, m){
        parent.resize(n);
        rang.resize(n);
        siz = vi(n, 1);
        forn(i, n){
            make_set(i);
        }
        int cnt = 0;
        forn(j, i+1){
            auto [x, y] = req[j];
            if(find_set(x) == find_set(y)){
                cnt++;
            } else {
                union_sets(x,y);
            }
        }
        vector<ll> temp;
        forn(j, n){
            if(j == find_set(j)){
                temp.push_back(siz[j]);
            }
        }
        int ans = 0;
        sort(temp.rbegin(), temp.rend());
        for(int j = 0; j < min(int(temp.size()), cnt+1); j++){
            ans += temp[j];
        }
        cout << min(ans-1, n-1) << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

