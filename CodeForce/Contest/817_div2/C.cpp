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
    multiset<int> a, b;
    vi a1(n,0), b1(n,0);
    forn(i, n){
        int x; cin >> x;
        a1[i] = x;
        a.insert(x);
    }
    vi c(n, 0);
    forn(i, n){
        int x; cin >> x;
        b1[i] = x;
        c[i] = x;
        b.insert(x);
    }
    vi ans1(n, 0), ans2(n, 0);
    ans1[n-1] = b1[n-1] - a1[n-1];
    for(int i = n-1; i > 0; i--){
        auto it = upper_bound(all(b1), a1[i]);
        if(it != b1.end()){
            int temp = *it;
            if()
            int idx = it - b1.begin();
            b1.erase(it);
            ans1[i-1] = *b1.end() - a1[i-1];
        }
    }
    b1.resize(n);
    forn(i, n){
        b1[i] = c[i];
    }
    for(int i = 0; i < n; i++){
        auto it = upper_bound(all(b1), a1[i]);
        if(it != b1.end()){
            int idx = it - b1.begin();
            int temp = *it;
            b1.erase(it);
            ans2[i] = temp - a1[i];
        }   
    }
    forn(i, ans1.size()){
        cout << ans2[i] << " ";
    }
    cout << endl;
    forn(i, ans1.size()){
        cout << ans1[i] << " ";
    }
    cout << endl;
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

