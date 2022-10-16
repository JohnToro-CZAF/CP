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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

vector<ll> dp(maxn), dpmin(maxn), dpmax(maxn);
vvi adj(maxn, vi());
vector<ll> si(maxn);
ll n, k;

void dfs(int s, int p, ll mi, ll mx){
    ll cnt = 0;
    for(int x : adj[s]){
        if(x == p) continue;
        cnt++;
    }
    vector<pair<ll, ll>> temp;
    
    for(int x : adj[s]){
        if(x == p) continue;
        dfs(x, s, mi/cnt, mx/cnt + ((mx % cnt) > 0));
        temp.push_back(make_pair(dpmax[x] - dpmin[x], x));
    }
    int it1 = 0;
    ll resmi = si[s] * mi;
    if(temp.size() != 0){
        sort(temp.rbegin(), temp.rend());
    }

    for(auto p : temp){
        if(it1 < mi%cnt){
            resmi += dpmax[p.second];
        } else {
            resmi += dpmin[p.second];
        }
        it1++;
    }
    int it2 = 0;
    ll resmx = si[s] * mx;
    for(auto p : temp){
        if(mx % cnt != 0){
            if(it2 < mx%cnt){
                resmx += dpmax[p.second];
            } else {
                resmx += dpmin[p.second];
            }
            it2++;
        } else {
            resmx += dpmax[p.second];
        }
    }
    dpmin[s] = resmi;
    dpmax[s] = resmx;
    // sth after calculated
    return;
}

void solve(){
    cin >> n >> k;
    adj = vvi(n, vi());
    si.clear(); dp.clear();
    dpmax.clear(); dpmin.clear();
    vi a(n);
    forn(i, n-1){
        int x; cin >> x;
        x--;
        a[i+1] = x;
    }
    for(int i = 1; i < n; i++){
        adj[a[i]].push_back(i);
        adj[i].push_back(a[i]);
    }
    ll ans = 0;
    forn(i, n){
        cin >> si[i];
    }
    dfs(0, -1, k, k);
    cout << max(dpmax[0], dpmin[0]) << endl;
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

