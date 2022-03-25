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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    forn(i, n){
        int x = s[i]-'a';
        cnt[x]++;
    }
    vi v;
    for(int i = 1; i*i <= k; i++){
        if(k%i == 0){
            if(i*i == k){
                v.push_back(i);
                continue;
            }
            v.push_back(k/i);
            v.push_back(i);
        }
    }
    vi tot(2001, 0);
    forn(i, 1999){
        forn(j, 26){
            tot[i+1] += floor(cnt[j]/(i+1))*(i+1);
        }
    }
    vi ans(2001, 0);
    for(int i = 1; i < 2001; i++){
        forn(k, 2001){
            if(tot[k] >= k*i){
                ans[i] = max(ans[i], k*i);
            }
        }
    }
    int res = 0;
    for(auto u : v){
        int tot = 0;
        // cout << u << " " << ans[u] << endl;
        res = max(res, ans[u]);
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

