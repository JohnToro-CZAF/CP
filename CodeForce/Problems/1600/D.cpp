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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

void solve(){
    int n;
    cin >> n;
    ll a[n];
    ll b[n];
    ll ans = 0;
    forn(i,n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> b[i];
        ans += a[i]*b[i];
    }
    ll temp = ans;
    for(ll i = 0; i < n; i++){
        ll res = ans;
        for(ll x = i-1, y = i; x >= 0 && y <= n-1; x--, y++){
            res -= a[x]*b[x] + a[y]*b[y];
            res += a[x]*b[y] + a[y]*b[x];
            temp = max(res, temp);
        }
    }    
    for(ll i = 0; i < n; i++){
        ll res = ans;
        for(ll x = i-1, y = i+1; x >= 0 && y <= n-1; x--, y++){
            res -= a[x]*b[x] + a[y]*b[y];
            res += a[x]*b[y] + a[y]*b[x];
            temp = max(res, temp);
        }
    }
    cout << temp << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

