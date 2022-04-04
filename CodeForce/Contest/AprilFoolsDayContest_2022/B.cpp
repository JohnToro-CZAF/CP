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
const ll MOD = 341550071728321; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

vector<int> parent, siz, mi;
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
    mi[v] = v;
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
        mi[a] = min(mi[a], mi[b]);
        mi[b] = min(mi[a], mi[b]);
        if(siz[a] > siz[b]){
            parent[b] = a;
            siz[a] += siz[b];
        } else {
            parent[a] = b;
            siz[b] += siz[a];
        }
    } else{
        return;
    }
}

void solve(){
    int d, n;
    cin >> d >> n;
    map<set<pair<pii, int> >, vi> check;
    map<int, set<pair<pii, int> > > su;
    forn(i, d){
        parent = vi(n);
        siz = vi(n);
        mi = vi(n);
        vector<pair<int, pii> > edges;
        forn(i, n){
            make_set(i);
        }
        forn(i, n-1){
            int a, b, c;
            cin >> a >> b >> c;
            a--; b--; 
            edges.push_back(make_pair(c, make_pair(a, b)));
        }
        sort(all(edges));
        set<pair<pii, int> > s;
        for(int i = int(edges.size())-1; i >= 0; i--){
            int cur = edges[i].first;
            int a = edges[i].second.first;
            int b = edges[i].second.second;
            int cura = mi[find_set(a)]; int curb = mi[find_set(b)];
            if(cura > curb){
                swap(cura, curb);
            }
            s.insert(make_pair(make_pair(cura, curb), cur));
            union_sets(a, b);
            // cout << cura << " " << curb << " " << cur << endl;
        }
        for(auto u : s){
            // cout << u.first.first << " " << u.first.second << " " << u.second << endl;
        }
        check[s].push_back(i+1);
        su[i] = s;
    }
    forn(i, d){
        cout << check[su[i]][0] << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}