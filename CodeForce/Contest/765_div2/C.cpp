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
const ll INF = 1e18;
const char min_char = 'a';
void solve(){
    int n, l, k;
    cin >> n >> l >> k;
    int d[n+2];
    int a[n+2];
    forn(i, n){
        cin >> d[i+1];
    }
    forn(i, n){
        cin >> a[i+1];
    }
    d[++n] = l;
    ll dp[n+1][n+1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = INF;
        }
    }
    dp[1][0] = 0;
    for(int i = 2; i <= n; i++){
        for(int t = 0; t <= k; t++){
            for(int j = i-1; j >= 1; j--){
                if(t < (i-j-1)) break;
                dp[i][t] = min(dp[j][t-(i-j-1)] + (d[i]-d[j])*a[j], dp[i][t]);
            }
        }
    }
    ll ans = INF;
    forn(i, k+1){
        ans = min(ans, dp[n][i]);
    }
    cout << ans << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

