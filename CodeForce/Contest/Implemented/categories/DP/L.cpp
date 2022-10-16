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
void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    forn(i, n){
        cin >> a[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0ll));
    forn(i, n){
        if(i+1 < n){
            if(n % 2 == 0){
                dp[i][i+1] = max(a[i+1], a[i]) - min(a[i+1], a[i]);
            } else {
                dp[i][i+1] = min(a[i+1], a[i]) - max(a[i+1], a[i]);            
            }
        }
        dp[i][i] = a[i] * ((n % 2 == 1) ? 1 : -1);
    }
    for(int j = 0; j < n; j++){
        for(int i = j-2; i >= 0; i--){
            // If A choose i, then B can choose i+1 or j
            ll op1 = min(dp[i+1][j-1] + a[i] - a[j], dp[i+2][j] + a[i] - a[i+1]);
            // If A choose j, then B can choose i or j-1
            ll op2 = min(dp[i+1][j-1] + a[j] - a[i], dp[i][j-2] + a[j] - a[j-1]);
            dp[i][j] = max(op1, op2);
        }
    }
    cout << dp[0][n-1] << endl;
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

