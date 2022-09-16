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
    // s <= b*k + (k-1)*n 
    // s <= k*(b+n);
    // s >= b*k
    // 28 <= 38 <= 48
    // 28 + 15 = 43
    // 38 = 9*4 + 2
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    if(k == 1){
        if(b == s){
            int t = n-1;
            cout << b << " ";
            while(t--){
                cout << 0 << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    if(s >= b*k && s <= b*k+(k-1)*n){
        ll t = n;
        ll temp = s - b*k;
        ll r = temp % (k-1);
        ll d = temp / (k-1);
        vector<ll> v;
        forn(i, d){
            v.push_back(k-1);
        }
        if(r > 0){
            v.push_back(r);
        }

        while(t--){
            ll ans = 0;
            if(!v.empty()){
                ans = v.back();
                v.pop_back();
            }
            if(t == n-1){
                ans += b*k;
            } 
            cout << ans << " "; 
        }
        cout << endl;
    } else {
        cout << -1 << endl;
        return;
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

