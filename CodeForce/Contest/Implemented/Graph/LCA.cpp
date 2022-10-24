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

const int maxn = 5e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

vi tin, tout;
vvi adj;
vvi up;
int timer;
int n, l;

void dfs(int s, int p){
    tin[s] = ++timer;
    up[s][0] = p;
    for(int i = 1; i <= l; i++){
        up[s][i] = up[up[s][i-1]][i-1];
    }
    for(int v : adj[s]){
        if(v == p) continue;
        dfs(v, s);
    }
    tout[s] = ++timer;
}

bool is_ancestor(int u, int v){
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v){
    if(is_ancestor(u, v)){
        return u;
    }
    if(is_ancestor(v, u)){
        return v;
    }
    for(int i = l; i >= 0; i--){
        if(!is_ancestor(up[u][i], v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}

void solve(){
    int q;
    cin >> n;
    l = ceil(log2(n));
    tin.assign(n, 0);
    tout.assign(n, 0);
    up.assign(n, vi(l+1));
    adj = vvi(n, vi());
    forn(i, n - 1){
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, 0);
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

