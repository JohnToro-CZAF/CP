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
void solve(){
    // Select some vertices such that the subgraph with
    // these vertices has even number of edges
    // number of edges = sum of deg / 2
    // deg 2 def 2
    int n, m;
    cin >> n >> m;
    vector<pii> a(n);
    int sum = 0;
    forn(i, n){
        cin >> a[i].first;
        a[i].second = i;
    }
    vector<pii> edge(m);
    forn(i, m){
        int x, y; cin >> x >> y;
        x--; y--;
        edge[i] = {x, y};
    }
    sort(all(a));
    if(m % 2 == 0){
        cout << 0 << endl;
        return;
    }
    int d1 = a[0].second, d2 = a[1].second;
    vi deg(n, 0);
    for(auto p : edge){
        deg[p.first]++;
        deg[p.second]++;
    }
    if(m % 2 == 1){
        if(deg[d1] % 2 == 1){
            cout << a[0].first << endl;
            return;
        } 
        if(deg[d2] % 2 == 1){
            cout << a[1].first << endl;
            return;
        }
        if()
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

