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
const ll INF = 1e18;
const char min_char = 'a';
void solve(){
    int n; cin >> n;
    vi a(n);
    int cnt0 = 0, cnt1 = 0;
    vi pos0, pos1;
    forn(i, n){
        cin >> a[i];
        a[i] %= 2;
        (a[i]%2==0) ? (cnt0++) : (cnt1++);
        if(a[i] == 0){
            pos0.push_back(i);
        } else {
            pos1.push_back(i);
        }
    }
    // if(n % 2 == 0){
    //     if(cnt0 != cnt1){
    //         cout << -1 << endl;
    //         return;
    //     }
    // } else {
    //     if(cnt0 != n/2 && cnt1 != n/2){
    //         cout << -1 << endl;
    //         return;
    //     }
    // }
    vi b(n);
    vi c(n);
    int t = 0;
    forn(i, n){
        b[i] = t;
        // cout << b[i] << " ";
        t ^= 1;
    }
    // cout << endl;
    t = 1;
    forn(i, n){
        c[i] = t;
        // cout << c[i] << " ";
        t ^= 1;
    }
    // cout << endl;
    ll ans = INF;
    vi pos0b, pos1b, pos0c, pos1c;
    forn(i, n){
        if(b[i] == 0){
            pos0b.push_back(i);
        } else {
            pos1b.push_back(i);
        }
    }
    forn(i, n){
        if(c[i] == 0){
            pos0c.push_back(i);
        } else {
            pos1c.push_back(i);
        }
    }
    if(int(pos0b.size()) == int(pos0.size())){
        ll cnt = 0;
        for(int i = 0; i < pos0b.size(); i++){
            cnt += abs(pos0b[i]-pos0[i]);
        }
        ll cnt1 = 0;
        for(int i = 0; i < pos1b.size(); i++){
            cnt1 += abs(pos1b[i]-pos1[i]);
        }
        ans = min(ans, cnt);
        ans = min(ans, cnt1);        
    } 
    if(int(pos0c.size()) == int(pos0.size())){
        ll cnt = 0;
        for(int i = 0; i < pos0c.size(); i++){
            cnt += abs(pos0c[i]-pos0[i]);
        }
        ll cnt1 = 0;
        for(int i = 0; i < pos1c.size(); i++){
            cnt1 += abs(pos1c[i]-pos1[i]);
        }
        ans = min(ans, cnt);
        ans = min(ans, cnt1);        
    } 
    if(ans == INF){
        cout << -1 << endl;
        return;
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

