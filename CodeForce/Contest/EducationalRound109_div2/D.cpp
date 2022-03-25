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
    int a[n];
    vi pos1;
    vi pos0;
    forn(i, n){
        cin >> a[i];
        if(a[i] == 0) pos0.push_back(i);
        else pos1.push_back(i);
    }
    int i = pos1.size();
    int j = pos0.size();
    vvi dp(i+1, vi(j+1, INF));
    dp[0][0] = 0;
    for(int x = 1; x <= j; x++){
        dp[0][x] = 0;
        if(i >= 1) dp[1][x] = abs(pos1[0]-pos0[x-1]);
    }
    for(int x = 0; x < i; x++){
        for(int y = 0; y < j; y++){
            if(dp[x][y] == INF) continue;
            dp[x+1][y+1] = min(dp[x+1][y+1], dp[x+1][y]);
            dp[x+1][y+1] = min(dp[x+1][y+1],dp[x][y] + abs(pos0[y]-pos1[x]));
        }
    }
    // cout << dp[1][1] << endl;

    cout << dp[i][j] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

