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
const char min_char = 'a';

struct triple {
    int x,y,val;
    triple(int x, int y, int val) : x{x}, y{y}, val{val} {}
};
vvi edge;
vvi graph;
vvi com;
vector<triple> req;
vi r;
vi parent;
map<pair<int, int>, int> value;
bool visited[maxn];

int cal(int s){
    return __builtin_popcount(s)%2;
}

void dfs(int s, int pre){
    if(s != 0) parent[s] = pre; 
    for(int u : edge[s]){
        if(u == pre) continue;
        else {
            dfs(u, s);
        }
    }
}
void dfs_graph(int s, vi & component){
    component.push_back(s);
    visited[s] = true;
    for(int u : graph[s]){
        if(visited[u]) continue;
        else {
            dfs_graph(u, component);
        }
    }
}

void dfs_helper(int s, int pre){
    visited[s] = true;
    if(pre != -1 && value[make_pair(s, pre)] == -1){
        return;
    }
    // cout << "du" << endl;
    for(int u : graph[s]){
        if(visited[u]) continue;
        else {
            if(r[s] != -1) r[u] = r[s]^value[make_pair(s, u)];
            dfs_helper(u, s);
        }
    }    
}

bool dfs_cal(int s, int pre){
    // cout << s << endl;
    visited[s] = true;
    for(int u : graph[s]){
        if(visited[u]) continue;
        else {
            if(r[u] == -1){r[u] = r[s]^value[make_pair(s, u)];}
            else if(cal(r[u]) != cal(r[s]^value[make_pair(s, u)])){
                // cout << u+1 << " " << s+1 << endl;
                return false;
            }
            if(!dfs_cal(u, s)){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    int n,m;
    cin >> n >> m;
    parent = vi(n);
    r = vi(n, -1);
    edge = vvi(n, vi());
    graph = vvi(n, vi());
    com.clear();
    value.clear();
    mem(visited, false);
    r[0] = 0;
    parent[0] = 0;
    cout << "start" << endl;
    // cout << "---" << endl;
    forn(i, n-1){
        int x,y, val;
        cin >> x >> y >> val;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
        value[make_pair(x, y)] = -1;
        value[make_pair(y, x)] = -1;
    // cout << "---" << endl;
        if(val != -1){
            graph[x].push_back(y);
            graph[y].push_back(x);
            value[make_pair(x, y)] = val;
            value[make_pair(y, x)] = val;
            req.push_back(triple(x, y, val));
    // cout << "---" << endl;

        }
    }
    // cout << "---" << endl;
    dfs(0, -1);
    forn(i, n){
        cout << i+1 << " " << parent[i]+1 << endl;
    }
    bool flag = true;
    forn(i, m){
        int x,y,val;
        cin >> x >> y >> val;
        x--; y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
        if((x == parent[y] || y == parent[x]) && value[make_pair(x, y)] != -1){
            if(value[make_pair(x, y)] != val){
                // cout << x << " " << y << endl;
                // cout << parent[x] << " " << parent[y] << endl;
                flag = false;
            }
        } else if(value[make_pair(x,y)] == -1){
            value[make_pair(y, x)] = val;
            value[make_pair(x, y)] = val;
        }
        req.push_back(triple(x,y,val));
    }
    if(!flag){
        cout << "NO" << endl;
        return;
    }
    forn(i, n){
        if(!visited[i]){
            vi component;
            dfs_graph(i, component);
            com.push_back(component);
        }
    }
    cout << "---" << endl;
    mem(visited, false);
    // cout << "---" << endl;

    dfs_helper(0, -1);
    // cout << "---" << endl;
    forn(i, n){
        cout << i+1 << " " << r[i] << endl;
    }
    mem(visited, false);   
    for(auto component : com){
        bool flag = false;
        int index;
    // cout << "---" << endl;

        int s = component.size();
        for(int i = 0; i < s; i++){
            if(r[component[i]] != -1){ flag = true; index = i;}
        }
        // cout << "---" << endl;
        if(!flag){index = 0; r[component[0]] = 0;}
        if(!dfs_cal(index, -1)){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "---" << endl;
    forn(i, n){
        cout << i+1 << " " << r[i] << endl;
    }
    cout << "YES" << endl;
    for(int i = 1; i < n; i++){
        int ans = r[i]^r[parent[i]];
        cout << i+1 << " " << parent[i]+1 << " " << ans << endl;
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

