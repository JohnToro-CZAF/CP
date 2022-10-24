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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi pos;
    int count = 0;
    while(count < s.size() && s[count] == '0'){
        count++;
    }
    s = s.substr(count, n);
    n = s.size();
    if(n == 0){
        cout << 0 << endl;
        return;
    }
    forn(i, n){
        if(s[i] == '0'){
            pos.push_back(i);
        }
    }
    if(pos.size() == 0){
        cout << s << endl;
        return;
    } 
    if(pos.size() == 1){
        if(n == 2){
            if(pos[0] == 0){
                cout << 1 << endl;
            } else {
                cout << "11" << endl;
            }
            return;
        } else {
            if(pos[0] == 0){
                cout << s.substr(1, n) << endl;
                return;
            } else {
                forn(i, n){
                    cout << '1';
                }
                cout << endl;
                return;
            }
        }
    }

    for(int i = 1; i < pos.size(); i++){
        pos[i] -= pos[0];
    }
    pos[0] = 0;

    string tot = "";
    int m = n - 1 - pos[0] + 1;
    // cout << m << endl;
    for(int i = 0; i < n-m+1; i++){
        string ans = "";
        string res = "";
        int it = 0;
        for(int j = i; j < i+m; j++){
            res += s[j];
        }
        while(res.size() < n){
            res = '0' + res;
        }
        cout << res << endl;
        for(int j = 0; j < n; j++){
            if(s[j] == '1' || res[j] == '1'){
                ans = ans + '1';
            } else {
                ans = ans + '0';
            }
        }
        // cout << ans << endl;
        if(tot.size() == 0){
            tot = ans;
        } else {
            if(ans > tot){
                tot = ans;
            }
        }
    }
    cout << tot << endl;
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

