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
const int INF = 1e9;
const char min_char = 'a';

vector<int> dp;
vector<string> s;
vector<vector<pii>> g;
vector<vector<int>> dirs = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
// errors : allow to go backward
vector<vector<int>> dirs1 = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<int> valid_node;
vector<int> p;
int n, m;

bool is_valid(int x, int y){
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int conv(pii p){
    return p.first*m + p.second;
}

pii in_conv(int pos){
    return {pos/m, pos%m};
}

struct state{
    int weight;
    pii node;
    state(int _weight) : weight(_weight) {};
    state(int _weight, pii _node) : weight(_weight), node(_node) {};
    bool operator<(const state &other) const {
        return weight > other.weight;
    }
};

priority_queue<state> pq;
void solve(){
    // int n, m;
    cin >> n >> m;
    // lesson: not to declare global vector with maxn size, it's safer to use
    // dp = vector<int>(n), cost more time to type but safer
    dp = vector<int>(n*m + 1, INF);
    s.resize(n);
    p.assign(m*n, -1);
    valid_node = vector<int>(n*m + 1, 1);
    g = vector<vector<pii>>(n*m+1);
    forn(i, n){
        cin >> s[i];
    }
    vector<pii> sources;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '.'){
                for(auto dir : dirs1){
                    int x = i + dir[0], y = j + dir[1];
                    // check if there is any neighbour is cacti, 
                    // if there is, this one is invalid
                    if(!is_valid(x, y)) continue;
                    if(s[x][y] == '#'){
                        valid_node[conv({i, j})] = 0;
                        break;
                    }
                    
                }
            }
            if(!valid_node[conv({i, j})]) continue;
            // sources are valid node with current state
            if(j == 0) sources.push_back({i, j});
            for(auto dir : dirs){
                int x = i + dir[0], y = j + dir[1];
                if(!is_valid(x, y)) continue;
                g[conv({i, j})].push_back({x, y});
            }
        }
    }
    forn(i, n){
        forn(j, m){
            // cout << i << " " << j << "childs: ";
            for(auto p : g[conv({i, j})]){
                // cout << p.first << " " << p.second << " ";
            }
            // cout << endl;
        }
    }

    for(pii src : sources){
        // initialize source with # or . distance
        p[conv(src)] = conv(src);
        int weight = (s[src.first][src.second] == '.') ? 1 : 0;
        dp[conv(src)] = weight;
        pq.push(state(weight, src));
    }
    while(!pq.empty()){
        state top = pq.top();
        // cout << top.weight << endl;
        pq.pop();

        if(top.weight > dp[conv(top.node)]) continue;

        for(pii to : g[conv(top.node)]){
            if(!valid_node[conv(to)]) continue;
            int w = (s[to.first][to.second] == '.') ? 1 : 0;
            if(top.weight + w < dp[conv(to)]){
                p[conv(to)] = conv(top.node);
                dp[conv(to)] = top.weight + w;
                pq.push(state(dp[conv(to)], to));
            }
        }
    }
    forn(i, n){
        forn(j, m){
            // cout << dp[conv({i, j})] << " ";
        }
        // cout << endl;
    }

    pii ans = {-1, -1};
    int bst = INF;
    for(int i = 0; i < n; i++){
        // cout << dp[conv({i, m-1})] << " ";
        if(dp[conv({i, m-1})] != INF){
            if(bst > dp[conv({i, m-1})]){
                bst = min(bst, dp[conv({i, m-1})]);
                ans = {i, m-1};
            }
        }
    }
    if(bst == INF){
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        pii cur = ans;
        while(p[conv(cur)] != conv(cur)){
            s[cur.first][cur.second] = '#';
            cur = in_conv(p[conv(cur)]);
        }
        s[cur.first][cur.second] = '#';
    }
    forn(i, n){
        cout << s[i] << endl;
    }
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

