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
const ll MAXN = 1e5;

vector<int> primes;
bool is_composite[MAXN]
int phi[MAXN];
void sieve(int n){
    std::fill(is_composite, is_composite+n, false);
    for(int i = 2; i < n; i++){
        if(!is_composite[i]) primes.push_back(i);
        for(int j = 2; i*j < n; j++){
            is_composite[i*j] = true;
        }
    }
}
// time complexity nlogn(loglogn)

void linear_sieve(int n){
    std::fill(is_composite, is_composite + n, false);
    for(int i = 2; i < n; i++){
        if(!is_composite[i]) primes.push_back(i);
        for(int j = 0; j < prime.size() && i*primes[j] < n; j++){
            is_composite[i*primes[j]] = true;
            // Stop when we are choosing the smallest prime divisor of i 
            if(i % primes[j] == 0) break;
        }
    }
}
// time complexity O(n)
// This sieve allow us to traverse all the primes and composite in only O(n) manner
// When we traverse through a composite then we also know what's the smallest prime factor of it
// Then we manipulate this factor - for multiplicative function

void multi_sieve(int n){
    std::fill(is_composite, is_composite + n, false);
    phi[1] = 1;
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
// time complexity O(n)

int func[MAXN], cnt[MAXN];
void multi_sieve_func(int n){
    std::fill (is_composite, is_composite + n, false);
    func[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) {
            prime.push_back (i);
            func[i] = 1; cnt[i] = 1;
        }
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                func[i * prime[j]] = func[i] / cnt[i] * (cnt[i] + 1);
                cnt[i * prime[j]] = cnt[i] + 1;
                break;
            } else {
                func[i * prime[j]] = func[i] * func[prime[j]];
                cnt[i * prime[j]] = 1;
            }
        }
    }
}
// Time complexity O(n)
// This sieve is deidacated to function "func" without the charactristic : i%p == 0 then f(i*p) = p*f(i)
// Just keeping the highest power of p that is the divisor of i ->f(i*p) = f(i/p^cnt) * f(p^(cnt+1))

void solve(){
    
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
