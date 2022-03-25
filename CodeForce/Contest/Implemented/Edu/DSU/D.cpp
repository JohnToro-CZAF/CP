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

vector<int> parent, rang, siz;
void make_set(int v) {
    parent[v] = v;
    rang[v] = 0;
    siz[v] = 1;
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
        siz[a] += siz[b];
        return;
    }
}

struct order {
    string s; int x, y;
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    parent.resize(n);rang.resize(n);siz.resize(n);
    forn(i, n){make_set(i);}
    vector<order> ord;
    set<pii> edges;
    forn(i, m){
        int x, y; cin >> x >> y; x-- ;y--;
        edges.insert(make_pair(x, y));
        edges.insert(make_pair(y, x));
    }
    forn(i, k){
        string s; int x, y; cin >> s >> x >> y; x--; y--;
        order orf = {s, x, y};
        if(s == "cut"){
            if(edges.find(make_pair(x, y)) != edges.end() && edges.find(make_pair(y, x)) != edges.end()){
                edges.erase(make_pair(x, y));
                edges.erase(make_pair(y, x));
            }
        }
        ord.push_back(orf);
    }
    for(auto p : edges){
        if(find_set(p.first) != find_set(p.second)){
            union_sets(p.first, p.second); 
        }
    }
    vs ans;
    for(int i = k-1; i >= 0; i--){
        if(ord[i].s == "ask"){
            ans.push_back((find_set(ord[i].x) == find_set(ord[i].y) ? "YES" : "NO")); 
        } else {
            if(find_set(ord[i].x) != find_set(ord[i].y)){
                union_sets(ord[i].x, ord[i].y);
            }
        }
    }
    reverse(all(ans));
    for(auto s : ans){
        cout << s << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

