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

vector<ll> b;
vector<ll> a;
vector<ll> w;
vvi adj;
set<ll> pos;
bitset<1000001> t;
bool dfs(int s, int p){
    ll mx = -1;
    bool chk = true;
    for(int v : adj[s]){
        if(v == p) continue;
        if(!dfs(v, s)){
            chk = false;
        }
        mx = max(b[v], mx);
    }
    if(mx != -1){
        if(b[s] >= mx){
            // pass
        } else {
            ll temp = mx - b[s];
            auto it = pos.lower_bound(temp);
            // cout << s << " " << b[s] << endl;
            if(it == pos.end()){
                return false;            
            } else {
                // cout << s << " " << *it << endl;
                b[s] = b[s] + *it;
            }
        }
    } else {
        // pass
    }
    return chk;
}

void solve(){
    int n, m;
    cin >> n >> m;
    a = vector<ll>(n);
    w = vector<ll>(m+1);
    t[0]=1;
    forn(i, n){
        cin >> a[i];
    }
    b = a;
    adj = vvi(n, vi());
    forn(i, n-1){
        int x, y; 
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    forn(i, m){
        cin >> w[i+1];
        t=t|(t<<w[i+1]);
    }
    for(int i=0;i<=1000000;i++){
        if(t[i]==1){
            pos.insert(i);
        }
    }
    sort(all(w));
    forn(i, m+1){
        if(i == 0){
            w[i] = 0;
        } else {
            w[i] = w[i-1] + w[i];
        }
    }
    if(!dfs(0, -1)){
        cout << -1 << endl;
        return;
    }
    forn(i, n){
        // cout << b[i] << " ";
    }
    cout << accumulate(all(b), 0ll) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}

