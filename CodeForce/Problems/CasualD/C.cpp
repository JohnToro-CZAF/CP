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

vector<ll> check(int length, vector<ll> &prefsum, vector<ll> &prefxor, int n){
    ll ans = -INF;
    int l, r;
    for(int i = 0; i + length - 1 < n; i++){
        int j = i + length - 1;
        ll tempsum = prefsum[j+1] - prefsum[i];
        ll tempxor = prefxor[j+1] ^ prefxor[i];
        if(tempsum - tempxor > ans){
            ans = max(tempsum - tempxor, ans);
            l = i, r = j;
        }
    }
    // cout << "check " << length << " " << ans << " " << l << " " << r << endl;
    return vector<ll>({ans, l, r});
}

void solve(){
    int m, q;
    cin >> m >> q;
    vi a(m);

    forn(i, m){
        cin >> a[i];
    }

    while(q--){
        int left, right; cin >> left >> right;
        left--; right--;
        vi b;
        forn(i, m){
            if(i >= left && i <= right){
                b.push_back(a[i]);
            }
        }
        int n = b.size();
        vector<ll> prefsum(n+1, 0);
        vector<ll> prefxor(n+1, 0);
        for(int i = 0; i < n; i++){
            prefsum[i+1] = prefsum[i] + b[i];
            prefxor[i+1] = prefxor[i] ^ b[i];
        }
        ll ans = prefsum[n] - prefxor[n];
        ll ansl = 0, ansr = n-1;
        // working on vector b only
        int l = 1, r = n, res = n;
        while(l <= r){
            int mid = (l+r)/2;
            auto vans = check(mid, prefsum, prefxor, n);
            if(vans[0] >= ans){
                ans = vans[0];
                ansl = vans[1]; ansr = vans[2];
                r = mid - 1;
                res = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << left + ansl+1 << " " << left + ansr+1 << endl;
        // return;
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

