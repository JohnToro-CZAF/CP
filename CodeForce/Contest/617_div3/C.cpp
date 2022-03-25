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

int n; string s;
pii last;
bool chk(int length){
    for(int i = 0; i+length-1 < n; i++){
        pii temp;
        for(int j = i; j < i+length; j++){
            char c = s[j];
            if(c == 'R') temp.first--;
            if(c == 'L') temp.first++;
            if(c == 'U') temp.second--;
            if(c == 'D') temp.second++;
        }
        if(temp == last){
            return true;
        }
    }
    return false;
}
int ct(int length){
    bool thereis = false;
    for(int i = 0; i+length-1 < n; i++){
        pii temp;
        for(int j = i; j < i+length; j++){
            char c = s[j];
            if(c == 'R') temp.first--;
            if(c == 'L') temp.first++;
            if(c == 'U') temp.second--;
            if(c == 'D') temp.second++;
        }
        if(temp == last){
            return i+1;
        }
    }
    return -1;
}

void solve(){
    cin >> n;
    cin >> s;
    last = make_pair(0, 0);
    map<pii, vi> m;
    m[last].push_back(-1);
    for(int i = 0; i < n; i++){
        char c = s[i];
        if(c == 'R') last.first++;
        if(c == 'L') last.first--;
        if(c == 'U') last.second++;
        if(c == 'D') last.second--;
        m[last].push_back(i);
    }
    // cout << last.first << " " << last.second << endl;
    int res = INF;
    pii best;
    bool found = false;
    for(auto [r, f] : m){
        int ans = INF;
        int p = f.size();
        for(int i = 0; i < p-1; i++){
            ans = f[i+1]-f[i];
            if(ans < res){
                res = ans;
                found = true;
                best = make_pair(f[i]+2, f[i+1]+1);
            }
        }
    }
    if(!found){
        cout << -1 << endl;
    } else {
        cout << best.first << " " << best.second << endl;
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

