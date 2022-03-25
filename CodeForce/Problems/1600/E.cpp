#include <bits/stdc++.h>
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

const int maxn = 1e7 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

vector<ll> minDiv(maxn, -1);
vector<ll> dp(maxn, 1);
ll ans[maxn];
// vector<ll> primes;
bool isPrime[maxn];
bool chope[maxn];
void precal(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < maxn; i++){
        if(isPrime[i]){
            minDiv[i] = i;
            for(ll j = (ll)i*i; j < maxn; j+=i){
                if(minDiv[j] == -1){
                    minDiv[j] = i;
                }
                isPrime[j] = false;
            }
        }
    }
    // cout << "loz" << minDiv[8] << endl;
    dp[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(isPrime[i]){
            dp[i] = i+1;
        } else {
            int temp = i;
            dp[i] = 1;
            while(temp % minDiv[i] == 0){
                temp /= minDiv[i];
                dp[i] = dp[i]*minDiv[i]+1;
            }
            dp[i] *= dp[temp];
        }
    }
    memset(chope, false, sizeof(chope));
    memset(ans, -1, sizeof(ans));
    for(int i = 1; i < maxn; i++){
        if(dp[i] < maxn && !chope[dp[i]]){
            ans[dp[i]] = i;
            chope[dp[i]] = true;
        }
    }
}

void solve(){
    int c;
    cin >> c;
    cout << ans[c] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    precal();
    // cout << minDiv[12] << endl;
    // cout << dp[6] << endl;
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

