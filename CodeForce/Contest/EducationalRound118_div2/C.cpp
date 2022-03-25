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
static T gcd (T a, T b) {long r, i;while(b!=0){r = a % b;a = b;b = r;}return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e18+4;

void solve(){
    ll n; ll h;
    cin >> n >> h;
    ll a[n+1];
    forn(i, n){
        cin >> a[i];
    }
    vector<ll> b(n+1);
    forn(i, n-1){
        b[i+1] = a[i+1] - a[i];
    }
    b[0] = 0;
    b[n] = INF;
    sort(all(b));
    ll sum[n];
    ll res = 0;
    forn(i, n){
        res += b[i];
        sum[i] = res;
    }
    ll ans = INF;
    for(int i = 0; i < n; i++){
        // cout << b[i] << " ";
    }
    // cout << "\n";
    for(int i = 0; i <= n; i++){
        if(i == n){
            ll can = h - sum[n-1];
            if(can >= b[n-1]){
                ans = min(ans, can);
            }
            // cout << can << endl;
            continue;
        }
        ll can = cei((h-sum[i]), (ll)(n-i));
        // cout << can << endl;
        if(can >= b[i] && can <= b[i+1]){
            ans = min(ans, can);
        }
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

