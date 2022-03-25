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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
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
typedef pii node; 
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve(){
    int n; cin >> n;
    vi a(n);
    vi b;
    set<int> s;
    forn(i, n){
        cin >> a[i];
        s.insert(a[i]);
    }
    for(int i = 1; i <= 2*n; i++){
        if(s.find(i) == s.end()){
            b.push_back(i);
        }
    }
    auto check = [&](int length, vector<int> a, vector<int> b){
        for(int i = 0; i < length; i++){
            if(a[i] > b[n-length+i]){
                return false;
            }      
        }
        return true;
    };
    // cout << "start" << endl;
    auto xn = [&](vector<int> a, vector<int> b){
        int low = 1, high = n, res = 0;
        while(low <= high){
            int mid = (low+high)>>1;
            if(check(mid, a, b)){
                low = mid+1;
                res = mid;
            } else {
                high = mid-1;
            }
        }
        return res;
    };
    // forn(i, n){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // forn(i, n){
    //     cout << b[i] << " ";
    // }
    // cout << endl;
    int mx = xn(a, b);
    int mi = n - xn(b, a);
    cout << mx-mi+1 << endl;
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