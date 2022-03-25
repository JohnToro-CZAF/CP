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

ll POW[maxn];

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

void fact(){
    ll t = 500000004;
    POW[0] = 1;
    for(int i = 1; i < maxn; i++){
        POW[i] = mul(POW[i-1], t);
    }
}
void solve(){
    int m, n, k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll> > > dp(n+1, vector<pair<ll,ll> >(m+1, make_pair(0, 0)));
    for(int i = 1; i <= m; i++){
        dp[i][i] = make_pair(mul(k,i), 0);
    }
    for(int i = 2; i <= n; i++){
        dp[i][1] = make_pair(k, i-1);
    }
    for(int j = 1; j <= m; j++){
        for(int i = j+1; i <= n; i++){
            if(j > 1){
                // dp[i][j] -> dp[i-1][j-1] + dp[i-1][j];
                if(dp[i-1][j-1].second < dp[i-1][j].second){
                    while(dp[i-1][j-1].second < dp[i-1][j].second){
                        dp[i-1][j-1].first = mul(dp[i-1][j-1].first, 2);
                        dp[i-1][j-1].second++;
                    }
                }
                if(dp[i-1][j-1].second > dp[i-1][j].second){
                    while(dp[i-1][j-1].second > dp[i-1][j].second){
                        dp[i-1][j].first = mul(dp[i-1][j].first, 2);
                        dp[i-1][j].second++;
                    }                    
                }
                dp[i][j].first = add(dp[i-1][j].first, dp[i-1][j-1].first);
                dp[i][j].second = dp[i-1][j].second+1;
            }
        }
    }
    cout << mul(dp[n][m].first, POW[dp[n][m].second]) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact();
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

