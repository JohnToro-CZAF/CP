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
    vi a(n);
    forn(i, n){
        cin >> a[i];
    }
    vi pos(n);
    forn(i, n){
        pos[a[i]] = i;
    }
    int l = pos[0], r = l;
    // cout << l << " " << r << endl;
    // 0: self+1, 1: self+3+1, 2: self+3+1, 3: self+1, 4: self
    int cur_mex = 1;
    int ans = 0;
    while(l >= 0 && r < n){
        if(cur_mex > n){
            break;
        }
        // current length is r - l + 1
        cout << l << " " << r << " ";
        // check if this is on the left of 
        // pointer or right of the pointer
        // x x 4 5 |0 1 2 3| 6 7 x x
        int length = r - l + 1;
        int disr = min(n-1-r, 2*cur_mex-length), disl = min(l, 2*cur_mex - length);
        // cout << disl << " " << disr << endl;
        // max_length is cur_mex * 2;
        int new_mex = cur_mex;
        int new_mex_pos = pos[new_mex];
        int self = 1;
        if(new_mex_pos > r){
            disr = min(disr, new_mex_pos - 1 - r);
        } else if(new_mex_pos < l){
            disl = min(disr, l - (new_mex_pos + 1));
        } else {
            self = 0;
            // nothing
        }
        cout << disl << " " << disr << " ";
        int cnt = ans;
        ans += self + disr + disl;
        for(int len = length + 2; len <= 2*cur_mex; len++){
            int s = len - length;
            for(int i = 1; i < s; i++){
                if(i <= disl && s-i <= disr){
                    ans++;
                }
            }
        } 
        cnt = ans - cnt;
        cout << cnt << endl;
        cur_mex++;
        cout << new_mex_pos << endl;
        if(new_mex_pos > r){
            r = new_mex_pos;
        } else if(new_mex_pos < l) {
            l = new_mex_pos;
        }
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

