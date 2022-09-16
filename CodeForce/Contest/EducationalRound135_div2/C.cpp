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

int ln(int n){
    int cnt = 0;
    while(n!= 0){
        cnt++;
        n /= 10;
    }
    return cnt;
}

void solve(){
    // cout << "testcase" << endl;
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, int> s;
    forn(i, n){
        cin >> a[i];
        s[a[i]]++;
    }
    forn(i, n){
        cin >> b[i];
        s[b[i]]--;
    }
    int ans = 0;
    vi a1, b1;
    for(auto [k, v] : s){
        if(k >= 10){
            if(v < 0){
                for(int i = 0; i < abs(v); i++){
                    b1.push_back(ln(k));
                    ans++;
                }
            } else if(v > 0) {
                for(int i = 0; i < abs(v); i++){
                    a1.push_back(ln(k));
                    ans++;
                }
            };
        } else {
            if(v < 0){
                for(int i = 0; i < abs(v); i++){
                    b1.push_back(k);
                }
            } else if(v > 0) {
                for(int i = 0; i < abs(v); i++){
                    a1.push_back(k);
                }
            };
        }
    }
    map<int, int> cnt;
    for(int x : a1){
        // cout << x << " ";
        cnt[x]++;
    }
    // cout << endl;
    for(int x : b1){
        // cout << x << " ";
        cnt[x]--;
    }
    // cout << endl;
    int t = 0;
    for(auto [k, v] : cnt){
        if(k == 1){
            ans -= abs(v);
            // continue;
        }
        if(v != 0){
            ans += abs(v);
        }
    }
    cout << ans << endl;
    // sort(all(a));
    // sort(all(b));
    // int ans = 0;
    // for(int l = 1; l <= 9; l++){
    //     vi a1, b1;
    //     map<int, int> cnt;
    //     for(int i = 0; i < n; i++){
    //         if(ln(a[i]) == l){
    //             cnt[a[i]]++;
    //         }
    //         if(ln(b[i]) == l){
    //             cnt[b[i]]--;
    //         }
    //     }
    //     for(auto [k, v] : cnt){
    //         // cout << k << " " << v << endl;
    //         ans += abs(v);
    //     }
    // }
    // cout << ans << endl;
    // 2 3 9 // if there is no number over here is equal to 8; if(len(a) == len(b) && a!=b) 
    // 1   8   100
    // for(all(length)) number of different within one length 
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

