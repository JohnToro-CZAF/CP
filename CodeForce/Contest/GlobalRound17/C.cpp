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
    int n; cin >> n;
    vii a(n);
    forn(i, n){
        a[i].first = i;
        a[i].second = i;
    }
    vi b(n), c(n);
    forn(i, n){
        cin >> b[i] >> c[i];
    }
    sort(all(a));
    auto check = [&](int length){
        int k = length;
        k--;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(cnt == length) break;
            if(b[a[i].second] >= k && c[a[i].second] >= length-1-k){
                k--;
                cnt++;
            }
        }
        if(cnt == length){  
            return true;
        } else {
            return false;
        }
    };
    int low = 1, high = n, res = -1;
    while(low <= high){
        int mid = (low+high)>>1;
        if(check(mid)){
            res = mid;
            low = mid + 1;
        } else {
            high = mid-1;
        }
    }
    if(res == -1){
        cout << 1 << endl;
        return;
    }
    cout << res << endl;
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

