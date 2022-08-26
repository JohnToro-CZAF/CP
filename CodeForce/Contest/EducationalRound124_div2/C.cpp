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
void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> b[i];
    }
    ll ans = INF;
    int fi = abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);
    int sec = abs(a[0]-b[n-1])+abs(b[0]-a[n-1]);
    ans = min(fi, sec);
    int indexb[2], indexa[2];
    int mi = INF;
    ll temp[4];
    ll t = 0;
    for(int i = 0; i < n; i++){
        if(abs(a[i]-b[0]) < mi){
            mi = abs(a[i]-b[0]);
            indexb[0] = i;
        }
    }
    temp[0] = mi;
    mi = INF;
    forn(i, n){
        if(abs(a[i]-b[n-1]) < mi){
            mi = abs(a[i]-b[n-1]);
            indexb[1] = i;
        }
    }
    temp[1] = mi;
    mi = INF;
    for(int i = 0; i < n; i++){
        if(abs(b[i]-a[0]) < mi){
            mi = abs(b[i]-a[0]);
            indexa[0] = i;
        }
    }
    temp[2] = mi;
    mi = INF;
    forn(i, n){
        if(abs(b[i]-a[n-1]) < mi){
            mi = abs(b[i]-a[n-1]);
            indexb[1] = i;
        }
    }
    temp[3] = mi;
    if(0 == indexa[0]){
        t += temp[0];
        t += temp[1];
        t += temp[3];
    }
    if(0 == indexa[1]){
        t += temp[0];
        t += temp[1];
        t += temp[2];
    }


    ans = min(ans, t);
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

