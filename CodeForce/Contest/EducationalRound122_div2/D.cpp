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
const int N = 1e3+5;
void solve(){
    vi dp(3*N, INF);
    dp[1] = 0;
    for(int i = 1; i < N; i++){
        for(int j = i; j >= 1; j--){
            int t = i/j;
            dp[i+t] = min(dp[i]+1, dp[i+t]);
        }
    }
    int mi = 0;
    int n, k; 
    cin >> n >> k;
    vi b(n+1), c(n+1); 
    forn(i, n){
        cin >> b[i+1];
        b[i+1] = dp[b[i+1]];
        mi = max(b[i+1], mi);
    }
    forn(i, n){
        cin >> c[i+1];
    }
    int K = n*mi+1;
    vvi dp1(n+1, vi(K+1, 0));
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= K; j++){
            if(i == 0){
                dp1[i][j] = 0;
                continue;
            }
            if(b[i] <= j){
                dp1[i][j] = max(dp1[i][j], dp1[i-1][j-b[i]]+c[i]);
            } 
            dp1[i][j] = max(dp1[i-1][j], dp1[i][j]);
        }
    }
    int ans = 0;
    for(int i = 0; i <= min(k, K); i++){
        ans = max(ans, dp1[n][i]);
    }
    cout << ans << endl;
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

