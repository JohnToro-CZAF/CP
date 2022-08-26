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
    ll w;
};
vector<int> parent, rang;
vector<edge> edges;
vvi adj;
bool cmp(const edge& a, const edge& b){
    return a.w > b.w;
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


void solve(){
    int n, m; ll s;
    cin >> n >> m >> s;
    parent.resize(n);
    rang.resize(n);
    ll allw = 0;
    ll alltake = 0;
    map<pair<int, int>, int> taken;
    map<pair<int, int>, int> pos;
    forn(i, n){
        make_set(i);
    }
    forn(i, m){
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        edge e;
        e.u = x;
        e.v = y;
        e.w = w; 
        taken[make_pair(x, y)] = 0;
        pos[make_pair(x, y)] = i+1;
        allw += w;
        edges.push_back(e);
    }
    sort(all(edges), cmp);
    int cnt = 0, it = 0;
    while(cnt < n-1 && it < m){
        int u = edges[it].u, v = edges[it].v;
        ll w = edges[it].w;
        if(find_set(u) != find_set(v)){
            union_sets(u, v);
            alltake += w;
            taken[make_pair(u, v)] = 1;
            cnt++;
        } 
        it++;
    }
    int i = 0;
    while(alltake < allw - s && i < m){
        if(i < m){
            int u = edges[i].u, v = edges[i].v;
            ll w = edges[i].w;
            if(!taken[make_pair(u, v)]){
                alltake += w;
                taken[make_pair(u, v)] = 1;
            }
        }
        i++;
    }   
    int count = 0; vi ans;
    for(auto [p, r] : taken){
        if(r == 0){
            count++;
            ans.push_back(pos[p]);
        }
    }
    cout << count << endl;
    sort(all(ans));
    for(auto u : ans){
        cout << u << " ";
    }
    cout << "\n";
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

