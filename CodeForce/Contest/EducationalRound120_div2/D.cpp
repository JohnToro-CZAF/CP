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
const ll MOD = 998244353;
const ll INF = 1e9;

ll fact[N], inv[N], invfact[N];

void factInverse() {
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for(long long i = 2; i < N; i++){
        fact[i] = (fact[i-1]*i)%MOD;
        inv[i] = MOD - (inv[MOD%i]*(MOD/i)%MOD);
        invfact[i] = (inv[i]*invfact[i-1])%MOD;
    }
}

ll mul(ll x, ll y){
    return (1LL*x*y)%MOD;
}

ll nCr(ll n, ll r){
    if(r > n){return 0;}
    return mul(mul(fact[n], invfact[r]), invfact[n-r]);
}

int count(string s){
    int cnt = 0;
    int n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt++;
    }
    return cnt;
}

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll ans = 0;
    int index = 0;
    vi v;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') v.push_back(i);
    }
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt++;
        if(cnt == k){
            index = i;
            break;
        }
    }
    if(k == 0){
        cout << 1 << endl;
        return;
    }
    if(cnt < k){
        cout << 1 << endl;
        return;
    }
    int keep = 0;
    for(int i = 0; i < index; i++){
        if(s[i] == '0') keep++;
    }
    int i = index;
    int length = index+1;
    ans += nCr(length, k);
    ans %= MOD;
    while(i <= n-2){
        while(i <= n-2 && s[i+1] == '0'){
            // cout <<i << " " << ans << endl;
            i++;
            length++;
        }
        ans += nCr(length,k);
        ans %= MOD;
        
        if(i<= n-2 && s[i+1] == '1'){
            // cout <<i << " " << ans << endl;
            ans += nCr(length-1, k);
            ans %= MOD;
            i++;
        }
    }
    cout << ans%MOD << endl;
}       


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    factInverse();
    solve();
}

