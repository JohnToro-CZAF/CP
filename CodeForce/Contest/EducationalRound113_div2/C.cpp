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

const int N = 2e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;

ll fact[N], inv[N], invfact[N];

void factInverse() {
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for(long long i = 2; i < N; i++){
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = MOD - (inv[MOD%i]*(MOD/i)%MOD);
        invfact[i] = (inv[i]*invfact[i-1])%MOD;
    }
}

ll mul(ll x, ll y){
    return (1LL*x*y)%MOD;
}

ll nCr(ll n, ll r){
    if(r > n){return 0;}
    return mul(mul(fact[n], invfact[r]), invfact[n-r]);
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    int maxa = 0;
    map<int, int> m;
    forn(i, n){
        cin >> a[i];
        maxa = max(maxa, a[i]);
        m[a[i]]++;
    }
    int next = 0;
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        if(a[i] != maxa){
            next = a[i];
        }
    }
    if(m[maxa] > 1){
        cout << fact[n] << endl;
    } else {
        if(maxa - next > 1){
            cout << 0 << endl;
        } else {
            ll num = m[next];
            ll remain = n-num-1;
            ll haha = fact[n] - mul(mul(nCr(n, num+1), fact[num]), fact[remain]);
            if(haha < 0){
                haha = MOD-abs(haha);
            }
            cout << haha%MOD << endl;
        }
    }
}       

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    factInverse();
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

