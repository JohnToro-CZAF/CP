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

int read(int n, int m, int mode){
    if(mode == 0){
        cout << "or " << n+1 << " " << m+1 << endl;
        cout.flush(); 
    } else {
        cout << "and " << n+1 << " " << m+1 << endl;
        cout.flush();
    }
    int x; cin >> x;
    return x;
}

void solve(){
    int n, k; cin >> n >> k;
    vi a(n);
    vi ans(n);
    forn(i, 3){
        a[i] = read(i, (i+1)%3, 0) + read(i, (i+1)%3, 1);
    }
    // cout << a[0] << " " << a[1] << " " << a[2] << endl;
    forn(i, 3){
        ans[i] = (a[(i)%3]+a[(i+2)%3]-a[(i+1)%3])/2;
    }
    for(int i = 3; i < n; i++){
        ans[i] = read(0, i, 0) + read(0, i, 1) - ans[0];
    }
    // for(auto u : ans) {
    //     cout << u << " ";
    // }
    // cout << endl;
    sort(all(ans));
    cout << "finish " << ans[k-1] << endl;
    cout.flush();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

