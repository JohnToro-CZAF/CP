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
const ll MAXN = 1e5+1;

template<typename T>
inline T mul(T x, T y){return (x%MOD)*(y%MOD)%MOD;}

template<typename T>
inline T add(T x, T y) {x%=MOD;y%=MOD;x += y;if(x >= MOD) x-=MOD;return x;}

vector<int> primes;
bool is_composite[MAXN];
vector<int> phi(MAXN, 0);

void multi_sieve(int n){
    std::fill(is_composite, is_composite + n, false);
    phi[1] = 0; // why ? since we are finding how many number i such that (i, n-i) = 1 -> finding how
    // many numbers i such that: (i, n) = 1 -> i != 0 and i != n -> base case n = 1: phi(n) = 0; (since we can not have any 
    // pair (a, b) such that a+b == 1 and (a, b) == 1) 
    // (a+b) = n && gcd(a, b) = 1 -> gcd(a, a+b) = 1 -> gcd(a, n) = 1. the number of numbers a: a >= 1, a<= n-1: (a, n) = 1 
    for(int i = 2; i < n; i++){
        if(!is_composite[i]){
            primes.push_back(i);
            phi[i] = i-1;
        }
        for(int j = 0; j < primes.size() && i*primes[j] < n; j++){
            is_composite[i*primes[j]] = true;
            if(i % primes[j] == 0){
                phi[i*primes[j]] = phi[i]*primes[j];
                break;
            } else {
                phi[i*primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }
}

ll cal(ll c, ll d, ll sumab){
    return phi[sumab/d] * (c * d / __gcd(d, c) % MOD) % MOD;
}

void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    for(ll sumab = 1; sumab < n; sumab++){
        ll c = n - sumab;
        for(ll d = 1; d*d <= sumab; d++){
            if(sumab % d == 0){
                ans = (ans + cal(c, d, sumab)) % MOD;
                if(d * d != sumab){
                    ans = (ans + cal(c, sumab/d, sumab)) % MOD;
                }
            }
        }
    }
    cout << ans << endl;
}       

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    multi_sieve(MAXN);
    int c = 1; 
    // cin >> c;
    while(c--){
        solve();
    }
}
