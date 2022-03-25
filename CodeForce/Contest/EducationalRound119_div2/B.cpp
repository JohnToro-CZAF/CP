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
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

void solve(){
    ll w, r;
    cin >> w >> r;
    int k, k1;
    int h, h1;
    cin >> k;
    ll a[k];
    forn(i, k){
        cin >> a[i];
    }
    cin >> k1;
    ll b[k1];
    forn(i, k1){
        cin >> b[i];
    }
    cin >> h;
    ll c[h];
    forn(i, h){
        cin >> c[i];
    }
    cin >> h1;
    ll d[h1];
    forn(i, h1){
        cin >> d[i];
    }
    ll m;
    m = (a[k-1] - a[0])*r;
    m = max((b[k1-1] - b[0])*r, m);
    m = max((c[h-1] - c[0])*w, m);
    m = max((d[h1-1]-d[0])*w, m);
    cout << m << endl;
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

