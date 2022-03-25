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

vvi adj;
vi cycle;
vi color;
vi pre;
vi num;
set<int> st;
void dfs(int s, int p){
    if(color[s] == 2){
        return;
    }
    if(color[s] == 1){
        int cur = p;
        cycle.push_back(cur);
        st.insert(cur);
        while(cur != s){
            cur = pre[cur];
            cycle.push_back(cur);
            st.insert(cur);
        }
        return;
    }
    pre[s] = p;
    color[s] = 1;
    for(auto v : adj[s]){
        if(v == p) continue;
        dfs(v, s);
    }
    color[s] = 2;
}   

ll dfs_helper(int s, int p){
    int tot = 1;
    // cout << s << " " << p << endl;
    if(adj[s].size() == 1){
        return 1;
    }
    for(auto u : adj[s]){
        if(u == p || st.find(u) != st.end()){
            continue;
        }
        tot += dfs_helper(u, s);
    }
    return tot;
}

void solve(){
    ll n; cin >> n;
    adj = vvi(n);
    num = vi(n, 0);
    color = vi(n, 0);
    pre = vi(n);
    st.clear();
    vi deg(n, 0);
    cycle.clear();
    forn(i, n){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    ll ans = n*(n-1);
    dfs(0, -1);
    for(auto u : cycle){
        ll res = dfs_helper(u, -1);
        // cout << res << endl;
        ans -= (ll)res*(res-1)/2;
    }
    cout << ans << endl;
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

