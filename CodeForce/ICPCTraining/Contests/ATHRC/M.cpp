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

const int maxn = 2e7 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
 
vector<ll> fact(maxn);

ll find_pow(ll m, ll p){
    if (m < p) return 0;
    ll div = m / p;
    return div + find_pow(m / p, p);
}

ll pow_rem(ll x, ll pow, ll divi){
    if (pow == 0) return 1;
    ll divv = pow / 2, remm = pow % 2;
    ll ans1 = pow_rem(x, divv, divi);
    if (remm == 0) return (ans1 * ans1) % divi;
    return (((ans1 * ans1) % divi) * x) % divi;
}

ll dmod(ll m, ll p, ll pk){
    // cout << m << " " << p << " " << pk << "\n";
    if (m == 0) return 1;
    ll div = m / p, remm = m % p;
    ll div2 = m / pk, remm2 = m % pk;
    ll ans1 = (pow_rem(fact[pk], div2, pk) * fact[remm2]) % pk;
    return  (ans1 * dmod(div, p, pk)) % pk;
}

ll inverse_mod(ll x, ll p, ll pk){
    return pow_rem(x, pk - pk/p - 1, pk);
}

void solve(){
    ll M, N, D;
    cin >> M >> N >> D;

    vector<ll> a, b, c, d, e, f, g;
    int DD = D;
    for (ll i = 2; i <= DD; i++){
        if (DD % i == 0){
            ll cnt = 0;
            while (DD % i == 0){
                cnt++;
                DD /= i;
            }
            a.push_back(i);
            b.push_back(cnt);
        }
    }

    forn(i, a.size()){
        int c1 = find_pow(M, a[i]), c2 = find_pow(M-N, a[i]), c3 = find_pow(N, a[i]);
        c.push_back(c1-c2-c3);
    }

    ll mn = c[0] / b[0];
    forn(i, a.size()){
        d.push_back(c[i] / b[i]);
        mn = min(mn, d[i]);
        // cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << "\n";
    }

    // cout << mn << "\n";

    forn(i, a.size()){
        ll x = D, p = a[i], pk = 1;

        forn(j, b[i]){
            x = x / p;
            pk *= p;
        }

        g.push_back(x);
        x = inverse_mod(x, p, pk);

        f.push_back(x);
        x = pow_rem(x, mn, pk);

        ll rem1 = c[i] - b[i] * mn;
        // cout << rem1 << " " << b[i] << "\n";
        if (rem1 >= b[i]){
            // cout << "can\n";
            e.push_back(0);
        // cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << " " << e[i] << "\n";
            continue;
        }


        // cout << x << " " << pk << " " << rem1<< "\n";

        fact[0] = 1;
        for (int j = 1; j <= pk; j++){
            if (j % p != 0) fact[j] = (fact[j-1] * j) % pk;
            else fact[j] = fact[j-1];
        }

        // cout << M << " " << p << " " << pk << "\n";
        ll z1 = dmod(M, p, pk), z2 = dmod(N, p, pk), z3 = dmod(M-N, p, pk);

        ll t = (x * z1) % pk;
        t = (t * inverse_mod(z2, p, pk)) % pk;
        t = (t * inverse_mod(z3, p, pk)) % pk;
        e.push_back(t);
        forn(j, rem1){
            e[i] = (e[i] * p) % pk;
        }
        // cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << " " << pk << " " << e[i] << "\n";
    }

    // forn(i, f.size()) cout << f[i] << " ";
    cout << "\n";

    ll ans = 0;
    forn(i, a.size()){
        ans = (ans + e[i] * f[i] * g[i]) % D;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    // cin >> c;
    while(T--){
        solve();
    }
}

