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
 
struct state {
    ll dist;
    pii node;
 
    state(pii _node) : node(_node) {};
    state(pii _node, ll _dist) : node(_node), dist(_dist) {};
 
    bool operator<(const state& other) const {
        return dist > other.dist;
    }
};
 
map<pii, ll> dp;
int n, m;
int p, q;
vector<string> s;
vector<map<pii, vector<pair<pii, ll>>>> g(2);
vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
vector<vector<pii>> sources(2);
map<char, pii> dits;
priority_queue<state> pq;
 
bool is_valid(int x, int y){
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}
 
void dijkstra_check(priority_queue<state> &pq, pii node, ll new_dist) {
    if (new_dist < dp[node]) {
        dp[node] = new_dist;
        pq.push(state(node, dp[node]));
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    dits['L'] = {0, 1}; dits['R'] = {0, -1};
    dits['U'] = {1, 0}; dits['D'] = {-1, 0};
    dits['#'] = {0, 0}; dits['.'] = {0, 0};
    cin >> n >> m;
    cin >> p >> q;
    s = vector<string>(n);
    forn(i, n){
        cin >> s[i];
    }
 
    //      x     
    //ooo  xlx
    //ooo xoiux
    //ooo  xux
    //      x
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[{i, j}] = INF;
            if(s[i][j] != '#'){
                for(auto dir : dirs){
                    int x = i + dir[0], y = j + dir[1];
                    if(!is_valid(x, y)) continue;
                    if(s[i][j] == '.')
                        sources[(i+j)%2].push_back({i, j});
                    if(dits[s[x][y]] != make_pair(0, 0)){
                        int x1 = x + dits[s[x][y]].first, y1 = y + dits[s[x][y]].second;
                        if(!is_valid(x1, y1) || (i == x1 && j == y1)) continue;
                        if((x1+y1)%2 != (i+j)%2) continue;
                        ll w = (i == x1 || j == y1) ? q : p;
                        if(g[(i+j)%2][{i, j}].size() == 0){
                            g[(i+j)%2][{i, j}] = vector<pair<pii, ll>>();
                        }
                        g[(i+j)%2][{i, j}].push_back({{x1, y1}, w});
                    }
                }
            }
        }
    }
    forn(i, n){
        forn(j, m){
            if(s[i][j] != '#'){
                for(auto p : g[(i+j)%2][{i, j}]){
                    cout << i << " " << j << ": " << p.first.first << " " << p.first.second << " " << p.second << endl;
                }
            }
        }
    }
    forn(_, 2){
        for(auto source : sources[_]){
            dp[source] = 0;
            pq.push(state(source, 0));
        }
        while(!pq.empty()){
            state top = pq.top();
            pq.pop();
 
            if(top.dist > dp[top.node]) continue;
 
            for(auto p : g[_][top.node]){
                pii to = p.first; ll w = p.second;
                if (top.dist + w < dp[to]) {
                    dp[to] = top.dist + w;
                    pq.push(state(to, dp[to]));
                }
            }
        }
    }
    forn(i, n){
        forn(j, m){
            cout << i << " " << j << " " << dp[{i, j}] << endl;
        }
    }
    ll ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(auto dir : dirs){
                int x = i + dir[0], y = j + dir[1];
                if(!is_valid(x, y)) continue;
                if(dp[{i, j}] != INF && dp[{x, y}] != INF){
                    ll res = dp[{i, j}] + dp[{x, y}];
                    ans = min(ans, res);
                    if(ans == 0){
                        cout << 0 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if(ans == INF){
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}