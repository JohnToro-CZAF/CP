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

const int N = 2e5 + 5;
const ll MOD = 1e9+7; // 998244353;
const ll INF = 1e9;

void solve(){
    int n;
    cin >> n;
    vector<double> p(n+1);
    forn(i, n){
        cin >> p[i+1];
    }
    vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int k = 0; k <= i; k++){
            dp[k][i] = (1-p[i]) * dp[k][i-1];
            if(k >= 1){
                dp[k][i] += (p[i]) * dp[k-1][i-1];
            }
        }
    }

    // n = 1,    2,            3,                                    4, 5, 6
    // k=0 1-p1 (1-p1)*(1-p2) (1-p1)(1-p2)(1-p3)
    // k=1 p1   (1-p1)p2+(1-p2)p1 (1-p3)((1-p1)p2+(1-p2)p1) + p3*((1-p1)*(1-p2))
    // k=2 0      p1*p2

    double ans = 0;
    forn(i, n+1){
        if(i > n/2){
            ans += dp[i][n];
        }
    }
    cout << setprecision(9) << ans << endl;
}        

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // factInverse();
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}

