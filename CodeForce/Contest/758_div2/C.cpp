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
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const int INF = 1e9;

void dfs_helper(int u, vector<vector<int> >& adj,
                bool visited[])
{
    if (visited[u])
        return;
 
    visited[u] = true;
 
    for (auto v : adj[u]) {
        if (!visited[v])
            dfs_helper(v, adj, visited);
    }
}

void getTransposeGraph(vector<vector<int> >& adj,
                       vector<vector<int> >& trans_adj)
{
    for (int u = 0; u < adj.size(); u++) {
        for (auto v : adj[u]) {
            trans_adj[v].push_back(u);
        }
    }
}

void initialize_visited(bool visited[], int n)
{
    for (int u = 0; u < n; u++)
        visited[u] = false;
}
vector<int> findAllMotherVertices(vector<vector<int> >& adj)
{
    int n = adj.size();
    bool visited[n];
    initialize_visited(visited, n);
    int last_dfs_called_on = -1;
 
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs_helper(u, adj, visited);
            last_dfs_called_on = u;
        }
    }

    initialize_visited(visited, n);
    dfs_helper(last_dfs_called_on, adj, visited);
 
    for (int u = 0; u < n; u++) {
          if (!visited[u]) {
            vector<int> emptyVector;
            emptyVector.push_back(-1);
 
            return emptyVector;
        }
    }
    int motherVertex = last_dfs_called_on;
    vector<vector<int> > trans_adj(n);
    getTransposeGraph(adj, trans_adj);
    initialize_visited(visited, n);
    dfs_helper(motherVertex, trans_adj, visited);
 
    vector<int> ans(n, 0);
 
    for (int u = 0; u < n; u++) {
        if (visited[u])
            ans[u] = 1;
    }
 
    return ans;
}


void solve(){
    int n;
    cin >> n;
    vvi adj(n);
    int a[n];
    int b[n];
    vii va;
    vii vb;
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> b[i];
    }
    forn(i, n){
        va.push_back(make_pair(a[i], i));
        vb.push_back(make_pair(b[i], i));
    }
    sort(all(va));
    sort(all(vb));
    vi bb;
    vi aa;
    for(int i = 0; i < n; i++){
        bb.push_back(vb[i].second);
    }
    for(int i = 0; i < n; i++){
        aa.push_back(va[i].second);
    }
    for(int i = n-1; i>=0; i--){
        int index = bb.back();
        bb.pop_back();
        adj[index] = bb;
    }
    for(int i = n-1; i>=0; i--){
        int index = aa.back();
        aa.pop_back();
        adj[index].insert(adj[index].end(), aa.begin(), aa.end());
    }
    vector<int> ans = findAllMotherVertices(adj);
    string s(n, '0');
    for(int i = 0; i < n; i++){
        if(ans[i] == 1) s[i] = '1';
    }
    cout << s << endl;
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

