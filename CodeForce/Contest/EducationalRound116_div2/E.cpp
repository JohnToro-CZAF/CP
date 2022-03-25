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
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int N = 1000;
const ll MOD = 998244353;
const ll INF = 1e9;

ll fact[N], inv[N], invfact[N];

void factInverse() {
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for(long long i = 2; i < N; i++){
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = MOD - (inv[MOD%i]*(MOD/i)%MOD);
        invfact[i] = (inv[i]*invfact[i-1])%MOD;
    }
}

int mul(ll x, ll y){
    return (1LL*x*y)%MOD;
}
template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (mul(base,power(base, powerRaised-1))); else return 1;}

int nCr(ll n, ll r){
    if(r > n){return 0;}
    return mul(mul(fact[n], invfact[r]), invfact[n-r]);
}
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
void solve(){
    int n, x;
    cin >> n >> x;
    vvi dp(n+1, vi(x+1, 0));
    int sum = 0;
    dp[n][0] = 1;
    for(int i = n; i > 1; i--){
        for(int j = 0; j < x; j++){
            int pw = 1;
            for(int k = i; k >= 0; k--){
                int nj = min(x, i+j-1);
                dp[k][nj] = add(dp[k][nj], mul(mul(dp[i][j], nCr(i, k)), pw));
                pw = mul(pw, nj - j);
            }
        }
    }
    for(int i = 0; i <= x; i++){
        sum += dp[0][i];
        sum %= MOD;
    }
    cout << sum << endl;
}       

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    factInverse();
    solve();
}



