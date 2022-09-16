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
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int N = 2e5 + 5;
const ll MOD = 1e9+7; // 998244353;
const ll INF = 1e9;

void printBi(int n){
    for(int i = 31; i >=0; i--){
        if((1<<i)&n){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
}

void solve(){
    int m; cin >> m;
    // printBi(m);
    // int s = m;
    // // while(s > 0){
    // //     s = (s-1)&m;
    // //     printBi(s);
    // // }
    for(int s=m; s; s=(s-1)&m){
        printBi(s);
        // use s for some thing
    }
    // Explanation: The code visit all submasks of m, without any repetition and in descending order.
    // Suppose if currently we have bitmask s. amd we want to move on to next bitmask. By subtracting
    // from s one unit, we will remove the rightmost set bit and all other to right of it will become 1: 11000 - 1 = 10111
    // Then we remove all the "extra" one bits that are not included in the mask m and therefore can be a part of a submask
    // Everytime we subtract so we only get smaller values
    
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

