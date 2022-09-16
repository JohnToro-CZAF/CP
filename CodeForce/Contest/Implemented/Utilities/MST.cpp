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
struct edge{
    int u, v;
    double w;
};
vector<int> parent, rang;
vector<edge> edges;
vvi adj;
bool cmp(const edge& a, const edge& b){
    return a.w < b.w;
}

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
        if (rang[a] == rang[b])
            rang[a]++;
    } else{
        return;
    }
}

void make(int n){
    parent.resize(n);
    rang.resize(n);
    forn(i, n){
        make_set(i);
    }
}

bool bpm(vvi bpGraph, int u,
         bool seen[], int matchR[])
{
    int N = bpGraph.size();
    int M = bpGraph[0].size();
    for (int v = 0; v < N; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v],
                                     seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}
// The roads to the workers
int maxBPM(vvi bpGraph)
{
    int N = bpGraph.size();
    int M = bpGraph[0].size();
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}

void solve(){
    int n, m, nw;
    cin >> n >> m;
    map<pair<int, int>, double> weight;
    vector<ll> ak(n);
    forn(i, n){
        cin >> ak[i];
    }
    vector<pair<int, int> > roads;
    adj = vvi(n, vi());
    forn(i, m){
        int x, y
        cin >> x >> y;
        x--; y--;
        edge e;
        double w = std::sqrt(ak[x] + ak[y]);
        e.u = x;
        e.v = y;
        e.w = w; 
        roads.push_back(make_pair(x, y));
        weight[make_pair(x, y)] = w;
        weight[make_pair(y, x)] = w;
        edges.push_back(e);
    }
    sort(all(edges), cmp);
    cin >> nw
    vvi BG(n, vi(nw, 0));
    for(int i = 0; i < nw; i++){
        int bx; cin >> bx;
        while(bx--){
            int v; cin >> v; v--;
            BG[v][i] = 1;
        }
    }
    // for(auto e : edges){
    //     // cout << e.v << " " << e.u << " " << e.w << endl;
    // }
    // cout << edges[0].w << endl;
    ll ans = -INF, cnt = 0, it = 0;
    while(cnt < n-1 && it < m){
        int u = edges[it].u, v = edges[it].v;
        ll w = edges[it].w;
        if(find_set(u) != find_set(v)){
            union_sets(u, v);
            // ans = max(ans, w); // maximum edge in the MST
            cnt++;
        } 
        it++;
    }
    cout << ans << endl;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

