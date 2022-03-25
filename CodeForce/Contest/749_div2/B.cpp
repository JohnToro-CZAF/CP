#include <bits/stdc++.h>
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
static T gcd (T a, T b) {long r, i;while(b!=0){r = a % b;a = b;b = r;}return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

vvi adj(maxn);
vvi component;
vi com;
bool visited[maxn];
void dfs(int v) {
    visited[v] = true ;
    com.push_back(v);
    for (size_t i = 0; i < (int) adj[v].size(); ++i) {
        int to = adj[v][i];
        if (!visited[to])
            dfs(to);
    }
}
void solve(){
    int n, m;
    // cout << "start" << endl;
    cin >> n >> m;
    forn(i, n+3){
        adj[i].clear();
    }
    forn(i, n+3){
        component.clear();
    }
    memset(visited, false, sizeof(visited));
    vii edge;
    forn(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(c);
        adj[c].push_back(a);
        edge.push_back(make_pair(a, c));
    }
    forn(i, n){
        if(!visited[i+1]){
            com.clear();1
            dfs(i+1);
            component.push_back(com);
        }   
    }
    for(int i = 0; i < int(component.size())-1; i++){
        edge.push_back(make_pair(component[i].back(), *component[i+1].begin()));
    }
    for(auto x : edge){
        cout << x.first << " " << x.second << endl;
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

