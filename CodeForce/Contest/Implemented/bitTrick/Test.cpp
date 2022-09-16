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
    // There are N persons and N tasks, each task is to be alloted to a single person. 
    // We are also given a matrix NxN of size , where cost[i][j]denotes, how much person i
    // is going to charge for task j. Now we need to assign each task to a person in such a way that the total
    // cost is minimum. Note that each task is to be alloted to a single person, and each person will be alloted only one task.
    int n; cin >> n;
    for(int mask = 0; mask < (1<<n); ++mask){
        int x = __builtin_popcount(mask);
        for(int j = 0; j <= n; j++){
            if(!((1<<j)&mask)){
                // turn on the jth bit, x = how many task have been set so far - the number of bits in mask
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask] + cost[x][j]);
            }
        }
    }
    cout << dp[(1<<n) - 1] << endl;
    //Time complexity of above algorithm is O(2^n(n^2)) and space complexity is O(2^n).
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

