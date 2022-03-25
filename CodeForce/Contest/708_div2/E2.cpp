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

const int maxn = 1e7 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
vector<bool> is_prime(maxn, true);

void pre_cal(){
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < maxn; i++){
        if(is_prime[i]){
            for(ll j = (ll)i*i; j < maxn; j+=i){
                is_prime[j] = 0;
            }
        }
    }
}
void solve(){
    int n, u;
    cin >> n >> u;
    vi a(n+1);
    map<int, vi> pos;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        for(int k = 1; k*k <= a[i]; k++){
            vi temp;
            if(a[i] % k == 0){
                if(k*k == a[i]){
                    if(is_prime[k]){
                        temp.push_back(k);
                    }
                } else {
                    if(is_prime[k]){
                        temp.push_back(k);
                    }
                    if(is_prime[a[i]/k]){
                        temp.push_back(a[i]/k);
                    }
                }
            }
            for(int j : temp){
                int cnt = 0;
                while(a[i] % j == 0){
                    a[i] /= j;
                    cnt++;
                }
                if((cnt&1) > 0){
                    a[i] *= j;
                }
            }
        }
        pos[a[i]].push_back(i);
    }
    vector<int> dp(n+2);
    dp[n+1] = n+1;
    for(int i = n; i > 0; i--){
        dp[i] = dp[i+1];
        int index = upper_bound(all(pos[a[i]]), i) - pos[a[i]].begin();
        int temp;
        if(index == pos[a[i]].size()){
            temp = n+1;
        } else {
            temp = pos[a[i]][index];
        }
        dp[i] = min(dp[i], temp);
    } 
    int l = 1;
    int ans = 0;
    while(l <= n){
        ans++;
        l = dp[l];
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    pre_cal();
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

