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
    vi x(n), m(n);
    vii pos, neg;
    forn(i, n){
        cin >> x[i] >> m[i];
        if (x[i] > 0) pos.push_back(make_pair(x[i], m[i]));
        else neg.push_back(make_pair(-x[i], m[i]));
    }
    if(pos.size() != 0){
        sort(pos.rbegin(), pos.rend());
    }
    if(neg.size() != 0){
        sort(neg.rbegin(), neg.rend());
    }
    // reverse(pos.begin(), pos.end());
    // reverse(neg.begin(), neg.end());
    // for(auto p : pos){
    //     cout << p.first << " " << p.second << endl;
    // }
    int ans = 0;
    // cout << pos.size() << endl;
    // cout << pos[1].second << endl;
    for(int i = 0 ; i < (int) pos.size(); i++){
        int no_steps = pos[i].second / k;
        int remainder = pos[i].second % k;
        // cout << pos[i].second << "\n";
        ans += no_steps * pos[i].first;
        if (i == pos.size() - 1){
            // cout << remainder << "\n";
            if (remainder > 0) ans += pos[i].first;
        }
        else{
            if (remainder > 0){
                pos[i+1] = {pos[i+1].first, pos[i+1].second - (k - remainder)};
                ans += pos[i].first;
            }
        }
    }

    // for (pii x: pos){
    //     cout << x.first << " ";
    // }

    forn(i, neg.size()){
        int no_steps = neg[i].second / k;
        int remainder = neg[i].second % k; 
        ans += no_steps * neg[i].first;
        if (i == neg.size() - 1){
            if (remainder > 0) ans += neg[i].first;
        }
        else{
            if (remainder > 0){
                neg[i+1] = {neg[i+1].first, neg[i+1].second - (k - remainder)};
                ans += neg[i].first;
            }
        }
    }

    // for (pii x: neg){
    //     cout << x.first << " ";
    // }

    cout << ans * 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c=1;
    // cin >> c;
    while(c--){
        solve();
    }
}

