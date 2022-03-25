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

bool isPrime[maxn];

void pre_cal(){
    mem(isPrime, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < maxn; i++){
        if(isPrime[i]){
            // cout << "cac" << endl;
            for(ll j = (ll)i*i; j < maxn; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void solve(){
    vector<ll> v;
    ll n; cin >> n;
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){  
            if(i*i == n){
                v.push_back(i);
                continue;
            }
            v.push_back(i);
            v.push_back(n/i);
        }
    }
    sort(all(v));
    ll s = sqrt(n)+1;
    vector<ll> dp(s+1, 0);
    vector<ll> anss(s+1);
    for(auto u : v){
        if(isPrime[u]){
            dp[u] = 1;
            anss[u] = u;
        }
    }
    for(auto u : v){
        if(dp[u] == 0){
            for(ll i = 1; i*i <= u; i++){
                if(u % i == 0){
                    ll t1 = sqrt(i);
                    ll t = sqrt(u/i);
                    if(t*t == u/i && t > 1){
                        if(dp[t]+1 > dp[u]){
                            dp[u] = max(dp[u], dp[t]+1);
                            anss[u] = t;
                        }
                    }   
                    if(t1*t1 == i && t1 > 1){
                        if(dp[t1]+1 > dp[u]){
                            dp[u] = max(dp[u], dp[t1]+1);
                            anss[u] = t1;
                        }
                    }
                }
            }
        }
    }
    vector<ll> an;
    ll chk;
    ll ans = 0;
    for(auto u : v){
        cout << u << " " << dp[u] << endl;
    }
    for(ll i = 1; i*i <= n; i++){
        if(n%i == 0){
            ll t = sqrt(n/i);
            ll t1 = sqrt(i);
            if(t*t == n/i && t > 1){
                if(dp[t]+1 > ans){
                    ans = max(ans, dp[t]+1);
                    // chk = max(chk, t);
                }
            }   
            if(t1*t1 == i && t1 > 1){
                if(dp[t1]+1 > ans){
                    ans = max(ans, dp[t1]+1);
                    // chk = max(chk, t1);
                }
            }
        }
    }
    // cout << dp[2] << endl;
    // cout << chk << endl;
    while(an.size() != ans){
        an.push_back(chk);
        chk = anss[chk];
        // cout << "loz" << endl;
    }
    sort(all(an));
    for(auto u : an){
        cout << u << " ";
    }
    cout << endl;
    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre_cal();
    int c;
    // cout << '?ca' << endl;
    cin >> c;
    while(c--){
        solve();
    }
}

