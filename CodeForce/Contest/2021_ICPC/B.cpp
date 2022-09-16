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

int convert(string s){
    int t = 1;
    int ans = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            ans += t * ((int) s[i] - '0');
            t *= 10;
        } else {
            return -1;
        }
    }
    return ans;
}

void solve(){
    string a, b;
    cin >> a >> b;
    int a1 = a.length();
    int b1 = b.length();
    string ans = "NaN";
    // for(int i = 0; i < a1; i++){
    //     if(a[i] - 'a' >= 0 && a[i] - 'a' <= 26){
    //         ans = "NaN";
    //         cout << ans << endl; 
    //         return;
    //     }
    // }
    // for(int i = 0; i < b1; i++){
    //     if(b[i] - 'a' >= 0 && b[i] - 'a' <= 26){
    //         ans = "NaN";
    //         cout << ans << endl; 
    //         return;
    //     }
    // }
    int a2 = convert(a);
    int b2 = convert(b);
    // cout << a2 << " " << b2 << endl;
    if(a2 == -1 || b2 == -1){
        cout << "NaN" << endl;
        return;
    } else {
        cout << a2 - b2 << endl;
        return;
    }
    // int c = stoi(a) - stoi(b);
    // cout << c << endl;
    // return;
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

