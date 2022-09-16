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
    int n, q;
    cin >> n >> q;
    vector<vector<ll> > ans(31, vector<ll>(n, -1));
    vector<vector<pair<ll,ll>> > G(n, vector<pair<ll,ll> >());
    while(q--){
        ll x, y, force;
        cin >> x >> y >> force;
        x--; y--;
        for(int i = 0; i < 31; i++){
            if(force&(1ll<<i)){
                
            } else {
                ans[i][min(x, y)] = 0;
                ans[i][max(x,y)] = 0;
            }

        }
        G[x].push_back(make_pair(y, force));
        G[y].push_back(make_pair(x, force));
    }

    for(int bit = 0; bit < 31; bit++){
        for(int i = 0; i < n; i++){
            ans[bit][i] = 0;
            for(auto p : G[i]){
                int u = p.first;
                int fbit = (p.second&(1<<bit)) ? 1 : 0;
                if(fbit && !ans[bit][u]){
                    ans[bit][i] = 1;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < 31; i++){
        for(int j = 0; j < n; j++){
            if(ans[i][j] == -1) ans[i][j] = 0;
        }
    }
    vector<ll> sum(n, 0ll);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 31; j++){
            sum[i] |= (1ll<<j)*ans[j][i];
        }
    }
    forn(i, n){
        cout << sum[i] << " ";
    }
    cout << endl;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}