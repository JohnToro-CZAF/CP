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
    int n,m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    sx--; sy--;
    vvi a = vvi(n, vi(m, 0));
    a[sx][sy] = 1;
    for(int x = 1; x <= d; x++){
        for(int y = 0; y <= x; y++){
            int z = x - y;
                forn(i, 4){
                    int t1 = sx + (i % 2 ? -1 : 1) * y; 
                    int t2 = sy + (i % 2 ? -1 : 1) * z;
                    if(t1 >= 0 && t1 < n && t2 >= 0 && t2 < m){
                        a[t1][t2] = 1;
                    }
            }
        }
    }
    // forn(i, n){
    //     forn(j, m){
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    bool flag1 = false;
    forn(i, n){
        bool flag = false;
        forn(j, m){
            if(a[i][j] == 0){
                flag = true;
            }
        }
        if(flag){
            flag1 = true;
        }
    }
    forn(j, m){
        bool flag = false;
        forn(i, n){
            if(a[i][j] == 0){
                flag = true;
            }
        }
        if(flag){
            flag1 &= flag;
        }
    }
    if(flag1){
        cout << m+n-2 << endl;
        return;
    } else{
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

