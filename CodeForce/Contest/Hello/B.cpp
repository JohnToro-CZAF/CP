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
    int l = INF;
    int r = 0;
    int ans = 0;
    int cnt = 0;
    int lastleft;
    int lastright;
    forn(i, n){
        // cout << "cnt" << cnt << endl;
        int left, right, value;
        cin >> left >> right >> value;
        if(cnt == 0){
            cnt++;
            l = left;
            r = right;
            ans += value;
            cout << ans << endl;
            continue;
        }
        if(cnt == 1){
            if(left == l && right == r){
                if(value < ans){
                    ans = value;
                }
            } else if(left <= l && right >= r){
                ans = value;
                l = left;
                r = right;
            } else if(left < l && right < r){
                l = left;
                lastright = ans;
                lastleft = value;
                ans += value;
                cnt++;
            } else if(left > l && right > r){
                r = right;
                lastright = value;
                lastleft = ans;
                ans += value;
                cnt++;
            }
            cout << ans << endl;
            continue;
        }
        if(cnt == 2){
            if(left == l && right == r){
                if(value < ans){
                    ans = value;
                    cnt = 1;
                }
            } else if(left <= l && right >= r){
                ans = value;
                l = left;
                r = right;
                cnt = 1;
            } else if(left < l && right < r){
                l = left;
                ans -= lastleft;
                lastleft = value;
                ans += value;
            } else if(left > l && right > r){
                r = right;
                ans -= lastright;
                lastright = value;
                ans += value;
            } else if(left == l && right < r){
                if(lastleft > value){
                    ans -= lastleft;
                    lastleft = value;
                    ans += value;
                }
            } else if(left > l && right == r){
                if(lastright > value){
                    ans -= lastright;
                    lastright = value;
                    ans += value;
                }
            }
            cout << ans << endl; 
        }
    }
    // cout << endl;
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

