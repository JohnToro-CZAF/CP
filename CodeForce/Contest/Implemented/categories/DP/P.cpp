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

template<typename T>
inline T mul(T x, T y){return (x%MOD)*(y%MOD)%MOD;}

template<typename T>
inline T add(T x, T y) {x%=MOD;y%=MOD;x += y;if(x >= MOD) x-=MOD;return x;}
vector<vector<int>> adj(maxn, vi());
vector<int> dpwhite(maxn, 1), dpblack(maxn, 1);
vector<int> visited(maxn);
vector<int> deg(maxn);
int n;

void dfs(int s, int p){
    visited[s] = 1;
    // cout << s << endl;
    if(deg[s] == 0){
        dpwhite[s] = 1;
        dpblack[s] = 1;
        return;
    }
    for(auto& u : adj[s]){
        int alr = 0;
        if(!visited[u]){
            deg[u]--; deg[s]--;
            // cout << "cac " << u << endl; 
            dfs(u, s);
            dpwhite[s] = mul(add(dpblack[u], dpwhite[u]), dpwhite[s]);
            dpblack[s] = mul(dpblack[s], dpwhite[u]);
            // cout << s << " " << dpwhite[s] << " " << dpblack[s] << endl;

        }
    }
}

void solve(){
    cin >> n;
    forn(i, n-1){
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        deg[x]++;
        adj[y].push_back(x);
        deg[y]++;
    }
    int cur = 0;
    dfs(cur, -1);
    dpwhite[cur] = add(dpwhite[cur], dpblack[cur]);
    cout << dpwhite[cur] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}
