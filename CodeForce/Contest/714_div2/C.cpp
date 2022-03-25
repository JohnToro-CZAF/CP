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

const ll MOD = 1e9+7; // 998244353;
const int maxn = 2e5+5;
vector<ll> ans(maxn);
void cal(){
    int n = maxn;
    vector<ll> dp(11, 0);
    dp[0] = 1;
    dp[1] = 1;
    ans[0] = 2;
    for(int j = 1; j < maxn; j++){
        for(int i = 9; i >= 0; i--){
            dp[i+1] = dp[i];
            dp[i] %= MOD;
            dp[i+1] %= MOD;
        }
        dp[0] = 0;
        dp[0] += dp[10];
        dp[1] += dp[10];
        dp[10] = 0;
        for(int i = 0; i <= 9; i++){
            ans[j] += dp[i];
            ans[j] %= MOD;
        }
    }
}       

void solve(){
    int n, m;
    cin >> n >> m;
    ll res = 0;
    while(n>0){
        int x = n%10;
        if(m < 10 - x){
            res += 1;
        } else {
            res += ans[m-(10-x)];
            res %= MOD;
        }
        n/=10;
    }
    cout << res%MOD << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cal();
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

