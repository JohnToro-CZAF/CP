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

const ll maxn = 5e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
const ll base = 31;

ll mul(ll x, ll y){
    return (1LL*x*y)%MOD;
}

ll add(ll x, ll y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}

ll Pow[2*maxn], Hash[2*maxn];

ll get_hash(ll i, ll j){
    return (Hash[j] - mul(Hash[i-1],Pow[j-i+1]) + MOD)%MOD;
}

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    s = " " + s + s;
    Pow[0] = 1;
    Hash[0] = 1;
    n*=2;
    for(ll i = 1; i <= n; i++){
        Pow[i] = mul(Pow[i-1],base);
    }
    for(ll i = 1; i <= n; i++){
        Hash[i] = add(mul(Hash[i-1],base),s[i]-min_char+1);
    }
    ll best = n/2;
    for(ll i = 1; i <= n/2; i++){
        ll low = 1, high = i, res = 0;
        while(low <= high){
            int mid = (low+high)>>1;
            if(get_hash(1, mid) == get_hash(i+1,i+mid)){
                res = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        if(res == i) continue;
        if(i+res+1 <= n && s[res+1] < s[i+res+1]){
            best = i;
            break;
        }
    }
    string ans = s.substr(1, best);
    while(ans.size() < k){
        ans += ans;
    }
    while(ans.size() > k){
        ans.pop_back();
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
