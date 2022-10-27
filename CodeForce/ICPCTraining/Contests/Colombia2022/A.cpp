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
const ll INF = 1e18;
const char min_char = 'a';
 
vector<vector<pair<ll, ll>>> adj;
vector<ll> dp;
 
void solve(){
    int n, m, num;
    cin >> n >> m >> num;
    adj = vector<vector<pair<ll, ll>>>(n, vector<pair<ll, ll>>());
    forn(i, m){
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        adj[x].push_back({y, w});
        // adj[y].push_back({x, w});
    }
    dp = vector<ll>(n, INF);
    while(num--){
        int u, v; cin >> u >> v; u--; v--;
        ll x; cin >> x;
        auto dijkstra = [&](int s, int d) {
            dp.assign(n, INF);
            vector<bool> u(n, false);
            dp[s] = x;
            priority_queue<pii, vector<pii>, greater<pii>> q;
            q.push({x, s});
            while (!q.empty()) {
                int v = q.top().second;
                int d_v = q.top().first;
                q.pop();

                if(d_v != dp[v]) continue; // Important

                for (auto edge : adj[v]) {
                    int to = edge.first;
                    int len = edge.second + x;
 
                    if (dp[v] + len < dp[to]) {
                        dp[to] = dp[v] + len;
                        q.push({dp[to], to});
                    }
                }
            }
            if(dp[d] == INF){
                cout << -1 << endl;
            } else {
                cout << dp[d] << endl;
            }
        };
        dijkstra(u, v);
    }
    cout << endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}