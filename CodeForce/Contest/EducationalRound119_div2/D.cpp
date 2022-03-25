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
    int n;
    cin >> n;
    int a[n];
    set<int> s;
    int m = 0;
    bool is[3];
    mem(is, false);
    forn(i, n){
        cin >> a[i];
        m = max(m, a[i]);
        is[a[i]%3] = true;
    }
    forn(i, n){
        if(a[i] < m && a[i] > 3*(m/3-1)){
            next = a[i];
        }
    }
    if(m % 3 == 0){
        if(!is[2]&&!is[0]){
            cout << m/3 << endl;
        } else {
            cout << m/3 + 1 << endl;
        }
    } else if(m%3 == 1){
        if(!is[2]){
            cout << m/3+1 << endl;
        } else {
            cout << m/3+2 << endl;
        }
    } else {
        if(!is[1]){
            cout << m/3+1 << endl;
        } else {
            cout << m/3+2 << endl;
        }   
    }
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

