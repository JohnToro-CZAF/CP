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
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
// using namespace __gnu_pbds;
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
 
const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
// typedef pii node; 
// typedef tree<node, null_type, less<node>,
//             rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll mul(ll x, ll y){
    return (1LL*x*y)%MOD;
}

void solve(){
    int n; cin >> n;
    int q; cin >> q;
    vi a(n);
    map<int, vi > div;
    map<int, map<int, int> > m;
    map<int, map<int, int> > actual;
    map<int, map<int, int> > count;
    map<int, int > gcount;
    vector<bool> is_prime(maxn, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < maxn;i ++){
        if(is_prime[i]){
            for(ll j = (ll)i*i; j < maxn; j += i){
                is_prime[j] = false;
            }
        }
    }
    for(int i = 1; i < maxn; i++){
        m[i][1] = 1;
    }
    for(int i = 1; i < maxn; i++){
        if(is_prime[i]){
            div[i].push_back(i);
            m[i][i] = 1;
            for(int j = 2*i; j < maxn; j+=i){
                div[j].push_back(i);
                m[j][i] = m[j/i][i]+1;
            }
        }
    }
    forn(i, n){
        cin >> a[i];
        for(auto p : div[a[i]]){
            actual[i][p] += m[a[i]][p];
            for(int j = 1; j <= m[a[i]][p]; j++){
                count[p][j]++;
            }
        }
    }
    int g = 0;
    forn(i, n){
        g = gcd(g, a[i]);
    }
    for(auto p : div[g]){
        gcount[p] = m[g][p]; 
    }
    while(q--){
        int index, x;
        cin >> index >> x;
        index--;
        vii process;
        for(auto p : div[x]){
            int temp = actual[index][p];
            actual[index][p] += m[x][p];
            int mx = 0;
            for(int i = temp+1; i <= actual[index][p]; i++){
                count[p][i]++;
                if(count[p][i] >= n){
                    mx = max(mx, i);
                }
            }
            if(mx > 0){
                process.push_back(make_pair(mx, p));
            }
        } 
        for(auto [mx, p] : process){
            if(mx > gcount[p]){
                g = mul(g,power(p,mx-gcount[p]));
                gcount[p] = mx;
            }
        }
        cout << g << endl;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}