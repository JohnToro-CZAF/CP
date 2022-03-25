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
struct edge{
    int u, v;
    ll w;
};
vector<int> parent, rang;
vector<edge> edges;

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


void solve(){
    int n, m;
    cin >> n >> m;
    parent.resize(n);
    rang.resize(n);
    // forn(i, n){
    //     make_set(i);
    // }
    forn(i, m){
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--; y--;
        edge e;
        e.u = x;
        e.v = y;
        e.w = w; 
        edges.push_back(e);
    }
    sort(all(edges), cmp);
    // for(auto e : edges){
    //     // cout << e.v << " " << e.u << " " << e.w << endl;
    // }
    map<ll, bool> is;
    map<ll, int> pos;
    ll ans = INF;
    int it, cnt;
    for(int i = 0; i < m; i++){
        if(!is[edges[i].w]){
            pos[edges[i].w] = i;
            is[edges[i].w] = true;
        }
    }
    for(int i = 0; i < m; i++){
        it = i; cnt = 0;
        it = pos[edges[i].w];
        // cout << it << " ";
        ll first, last;
        forn(j, n){
            make_set(j);
        }
        while(cnt < n-1 && it < m){
            if(find_set(edges[it].v) != find_set(edges[it].u)){
                // ans += edges[it].w;
                union_sets(edges[it].v, edges[it].u);
                cnt++;
                if(cnt == 1){
                    first = edges[it].w;
                } else if(cnt == n-1){
                    last = edges[it].w;
                }
            } 
            it++;
        }
        if(cnt == n-1){
            // cout << it << " " << ans << endl;
            // Loop thourgh all the starting edge -> then MST
            ans = min(ans, last-first);
        }
    }
    if(ans != INF){
        cout << "YES" << endl;
        cout << ans << endl;
    } else {
        cout << "NO" << endl;
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

