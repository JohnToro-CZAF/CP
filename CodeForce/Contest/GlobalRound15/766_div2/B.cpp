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
const int maxp = maxn;

// vector<int> primes;
// // precal primes from 0 -> sqrt(n)
// void precal(){
//     int is_prime[maxp];
//     memset(is_prime, 1, sizeof(is_prime));
//     is_prime[0] = is_prime[1] = 0;
//     for(int i = 2; i < maxp; i++){
//         if(is_prime[i]){
//             for(int j = i*i; j < maxp; j+=i){
//                 is_prime[j] = 0;
//             }
//         }
//     }
//     for(int i = 0; i < maxp; i++){
//         if(is_prime[i]){
//             primes.push_back(i);
//             post_primes.push_back(i);
//         }
//     }
// }

void solve(){
    int n, m;
    cin >> n >> m;
    vi posx = {0, 0, m-1, m-1};
    vi posy = {0, n-1, 0, n-1};
    vi ans;
    forn(i, n){
        forn(j, m){
            int m = 0;
            forn(k, 4){
                m = max(m, abs(posx[k]-j)+abs(posy[k]-i));
            }
            ans.push_back(m);
        }
    }
    sort(all(ans));
    for(auto u : ans){
        cout << u << " ";
    }
    cout << endl;
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

