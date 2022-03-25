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

const int N = 1e6 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

ll POW[N], fact[N], inv[N], invfact[N];

// template<typename T>
// inline T mul(T x, T y){return (x%MOD)*(y%MOD)%MOD;}

// template<typename T>
// inline T add(T x, T y) {x%=MOD;y%=MOD;x += y;if(x >= MOD) x-=MOD;return x;}
ll mul(ll x, ll y){
    return (x%MOD)*(y%MOD)%MOD;
}
ll add(ll x, ll y) {
    x%=MOD;
    y%=MOD;
    x += y;
    if(x >= MOD) x-=MOD;
  return x;
}

ll modInverse(int a){
    for (int x = 1; x < MOD; x++){
        if (((a%MOD) * (x%MOD)) % MOD == 1) return x;
    }
}

void factInverse() {
    ll t = 500000004;
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    POW[0] = 1; POW[1] = t;
    for(long long i = 2; i < N; i++){
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = MOD - (inv[MOD%i]*(MOD/i)%MOD);
        invfact[i] = (inv[i]*invfact[i-1])%MOD;
        POW[i] = mul(POW[i-1], t);
    }
}

ll nCr(ll n, ll r){
    if(r > n || r < 0 || n < 0){return 0;}
    return mul(mul(fact[n], invfact[r]), invfact[n-r]);
}

void solve(){
    int m, n, k;
    cin >> n >> m >> k;
    ll ans = (n==m) ? n : 0ll;

    for(ll i = 1; i <= m; i++){
        ans = add(ans, mul(mul(nCr(n-i-1, m-i), POW[n-i]),i));
    }
    cout << mul(ans,k) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    factInverse();
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

