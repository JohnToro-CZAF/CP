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
    map<ll, ll> cnt;
    int l = 1;
    forn(i, 10){
        if(!i){
            l*=1;
            cnt[i] = l;
        } else {
            l *= i;
            cnt[i] = l;
        }
    }
    ll x;
    cin >> x;
    if(x == 1){
        cout << 0 << endl;
        return;
    }
    vector<pair<ll, ll>> ans;
    while(x > 0){
        int idx;
        for(int i = 9; i >= 0; i--){
            if(x >= cnt[i]){
                idx = i;
                break;
            }
        }
        ll temp = x/cnt[idx];
        x -= temp*cnt[idx];
        ans.push_back({idx, temp});
    }
    reverse(all(ans));
    if(ans[0].first!=0){
    for(auto pa:ans){
        for(int i=0;i<pa.second;i++){
            cout<<pa.first;
        }
        }
        cout << endl;
        return;
    }
    cout<< ans[1].first;
    ans[1].second--;
    for(auto pa:ans){
        for(int i=0;i<pa.second;i++){
            cout<<pa.first;
        }
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

