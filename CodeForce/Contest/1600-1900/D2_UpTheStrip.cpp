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
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 4e6 + 5;
ll MOD;
const ll INF = 1e9;
ll mul(ll x, ll y){
    return (1LL*x*y)%MOD;
}
ll add(ll x, ll y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
void solve(){
    ll n; 
    cin >> n >> MOD;
    vector<ll> dp(maxn, 0);
    vector<ll> sum(maxn, 0);
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = add(dp[i], dp[i-1]);
        dp[i] = add(dp[i], 1);
        if(i > 2) dp[i] = add(dp[i], dp[i-1]);
        for(int j = 2*i; j <= n; j+= i){
            dp[j] = add(dp[j], dp[i]);
            dp[j] = add(dp[j], MOD-dp[i-1]);
        }
    }
    cout << dp[n] << endl;
}       

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

