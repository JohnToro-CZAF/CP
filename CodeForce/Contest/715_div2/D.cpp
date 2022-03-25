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

string mix(string a, string b, char c, int n){
    vi posa = {-1}, posb = {-1};
    string ans = "";
    for(int i = 0; i < 2*n; i++){
        if(a[i] == c) {
            posa.push_back(i);
        }
        if(b[i] == c){
            posb.push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        // cout << posa[i] << " " << posb[i] << endl;
        for(int j = posa[i]+1; j < posa[i+1]; j++){
            ans += a[j];
        }
        for(int j = posb[i]+1; j < posb[i+1]; j++){
            ans += b[j];
        }
        ans += c;
    }
    // cout << ans << endl;
    // cout << ans.size();
    for(int i = posa[n]+1; i < 2*n; i++){
        ans += a[i];
    }
    for(int i = posb[n]+1; i < 2*n; i++){
        ans += b[i];
    }
    // cout << c << endl;
    // cout << ans.size() << endl;
    return ans;
}

void solve(){
    int n; cin >> n;
    vs s0;
    vs s1;
    forn(i, 3){
        string s; cin >> s;
        int cnt0 = 0;
        forn(j, 2*n){
            cnt0 += s[j]=='0';
        }
        if(cnt0 >= n){
            s0.push_back(s);
        } else {
            s1.push_back(s);
        }
    }
    if(s0.size() >= 2){
        // cout << s0[0] << " " << s0[1] << endl;
        cout << mix(s0[0], s0[1], '0', n) << endl;
    }  else {
        cout << mix(s1[0], s1[1], '1', n) << endl;
    }
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

