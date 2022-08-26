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
typedef push_back pb;
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

const int maxn = 3e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

pii ninety(int xx, int yy){
    return {-yy, xx};
}

int projection(int uu, int vv, int next){
    pii v1 = {x[uu] - x[vv], y[uu] - y[vv]}, v2 = {x[next] - x[vv], y[next] - y[vv];
    pii nt = ninety(v1.first, v1.second);
    int k1 = ((v2.first * v1.first + v2.second * v1.second) / abs(v2.first * v1.first + v2.second * v1.second)) * 
    int k2 = (nt.first * v1.first + nt.second * v1.second) / abs(nt.first * v1.first + nt.second * v1.second);
    return k1 * k2;
}

pair<double, double> normalize(int xx, int yy){
    return {(double) xx / sqrt(xx * xx + yy * yy)}
}

double angle(uu, vv, next){

    return; 
}

vi x(maxn), y(maxn), u(maxn), v(maxn);


void solve(){
    int n, m;
    cin >> n >> m;
    forn(i, n) cin >> x[i + 1] >> y[i + 1];
    v<vi> adj_point(m + 1);
    forn(i, m){
        cin >> u[i + 1] >> v[i + 1];
        adj_point[u[i + 1]].pb(v[i + 1]);
        adj_point[v[i + 1]].pb(u[i + 1]);
    }

    v<vi> adj(m + 1);
    vector<map<int, int>> cw(n + 1), acw(n + 1), mcw(n + 1), macw(n + 1);
    forn(i, m){
        int uu = u[i + 1], vv = v[i + 1]
        mcw[uu][vv] = 10;
        macw[uu][vv] = 0;
        for (int next: adj_point[vv]){
            if (angle(uu, vv, next) < mcw[uu][vv]){
                mcw[uu][vv] = angle(uu, vv, next);
                cw[uu][vv] = next;
            }

            if (angle(uu, vv, next) > macw[uu][vv]){
                macw[uu][vv] = angle(uu, vv, next);
                acw[uu][vv] = next;
            }
        }

        mcw[vv][uu] = 10;
        macw[vv][uu] = 0;
        for (int next: adj_point[uu]){
            if (angle(vv, uu, next) < mcw[vv][uu]){
                mcw[vv][uu] = angle(vv, uu, next);
                cw[vv][uu] = next;
            }

            if (angle(vv, uu, next) > macw[vv][uu]){
                macw[vv][uu] = angle(vv, uu, next);
                acw[vv][uu] = next;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    // cin >> c;
    c = 1;
    while(c--){
        solve();
    }
}

