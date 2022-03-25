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
    vi dp(n+2, 0);
    vi cnt(n+2, 0);
    int mx = 0;
    forn(i, n){
        cin >> a[i];
        cnt[a[i]]++;
        mx = max(mx, a[i]);
    }
    sort(all(a));
    ordered_set s;
    forn(i, n){
        s.insert({a[i], i});
    }
    // cout << "start" << endl;
    int last = a[0];
    for(int i = max(last,0); i < n+2; i++){
        if(cnt[i] > 0){
            last = i;
            dp[i] = s.order_of_key({i, 0});
        } else {
            if(last == mx){
                dp[i] = dp[last]+cnt[last];
                // cout << dp[i] << " ";
                continue;
            }
            dp[i] = dp[last];
        }
        // cout << dp[i] << " ";
    }
    // cout << endl;
    // vector<pair<ll, vi> > msk;
    // for(int i = 0; i < 56; i++){
    //     for(int j = i; j < 56; j++){
    //         for(int k = j; k < 56; k++){
    //             ll mask = 0;
    //             mask += (1ll<<i)+(1ll<<j)+(1ll<<k);
    //             // cout << mask << " ";
    //             vi temp = {i, j, k};
    //             msk.push_back(make_pair(mask, temp));
    //         }
    //     }
    // }
    // sort(all(msk));
    // for(auto mask : msk){
    //     cout << mask.first << " ";
    // }
    auto get = [&](int x){
        int lg = x <= 1 ? 0 : __lg(x-1)+1;
        return (1<<lg)-x;
    };
    // auto check = [&](vi msk){
    //     ll ans = 0;
    //     cout << "iter" << endl;
    //     forn(i, 3){
    //         ans += 1ll<<msk[i];
    //         cout << msk[i] << " ";
    //     }
    //     // cout << endl;
    //     // cout << ans << endl;
    //     if(ans < n){
    //         return false;
    //     }
    //     forn(i, 3){
    //         for(int j = n; j >= 0; j--){
    //             if(dp[j] <= (1ll<<msk[i])){
    //                 // cout << "yes" << endl;
    //                 if(dp[n+1]-dp[j] > (1ll<<msk[(i+1)%3]) + (1ll<<msk[(i+2)%3])){
    //                     break;
    //                 } else {
    //                     // cout << "ok" << endl;
    //                     for(int nxt = 1; nxt <= 2; nxt++){
    //                         ll target = 1ll<<msk[(i+nxt)%3];
    //                         ll another = (nxt==1) ? 1ll<<msk[(i+2)%3] : 1ll<<msk[(i+1)%3];
    //                         // cout << "infor" << endl;
    //                         // cout << target << " " << another << endl;
    //                         auto it = lower_bound(dp.begin()+j, dp.end(), target+dp[j]);
    //                         if(*it == target+dp[j]){
    //                             int index = it - dp.begin();
    //                             if(dp[n+1]-dp[index] <= another){
    //                                 return true;
    //                             }
    //                         } else {
    //                             if(it != dp.begin()){
    //                                 it--;
    //                             }
    //                             int index = it - dp.begin();
    //                             if(dp[n+1]-dp[index] <= another){
    //                                 return true;
    //                             }
    //                         }
    //                     }
    //                     continue;
    //                 }
    //             }
    //         }
    //     }
    //     // cout << "false " << endl;
    //     return false;
    // };
    // cout << "start" << endl;
    int ans = INF;
    for(int i = 0; i <= n+1; i++){
        int cut = get(dp[i]);
        // cout << cut << dp[i] << endl;
        int remain = n - dp[i];
        for(int j = 0; (1<<j) <= remain; j++){
            auto it = lower_bound(dp.begin()+i, dp.end(), (1<<j)+dp[i]);
            int index;
            if(*it == (1<<j)+dp[i]){
                index = it - dp.begin();
            } else {
                if(it != dp.begin()){
                    it--;
                }
                index = it-dp.begin();
            }
            ans = min(ans, get(dp[n+1]-dp[index])+(1<<j)-(dp[index]-dp[i])+cut);
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

