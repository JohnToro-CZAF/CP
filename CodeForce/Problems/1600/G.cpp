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
inline T gcd (T a, T b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return abs(a);
}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

ll a[maxn];
ll b[maxn];
int n, m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    forn(i, n){
        cin >> a[i];
    }
    forn(i, m){
        cin >> b[i];
    }
    ll g = a[1] - a[0];
    if(n == 1){
        for(int i = 0; i < m; i++){
            cout << a[0]+b[i] << " ";
        }
        cout << "\n";
        return 0;
    }
    for(int i = 1; i < n; i++){
        g = gcd(g, a[i] - a[0]);
    }
    for(int i = 0; i < m; i++){
        ll temp = a[0]+b[i];
        cout << gcd(g, temp) << " ";
    }
    cout << "\n";
}

