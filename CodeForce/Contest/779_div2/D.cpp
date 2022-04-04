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
    int l, r;
    cin >> l >> r;
    int n = r-l+1;
    int count0[18][2];
    int count1[18][2];
    vi a(n);
    mem(count0, 0);
    mem(count1, 0);
    for(int i = l; i <= r; i++){
        for(int j = 0; j < 18; j++){
            count0[j][0] += ((i>>j)%2 == 0);
            count1[j][0] += ((i>>j)%2 == 1);
        }
    }
    forn(i, n){
        cin >> a[i];
        for(int j = 0; j < 18; j++){
            count0[j][1] += ((a[i]>>j)%2 == 0);
            count1[j][1] += ((a[i]>>j)%2 == 1);
        }
    }
    vi ans(18, 0);
    vi ch(18, 0);
    bool chk = false;
    for(int i = 0; i < 18; i++){
        if(count0[i][0] == count1[i][0]){
            ch[i] = 1;
            chk = true;
        } else {
            if(count0[i][0] != count0[i][1]){ans[i] = 1;}
            else ans[i] = 0;
        }
    }
    if(chk){
        int mid = r - (r-l+1)/2;
        for(int j = 0; j < 18; j++){
            if(ch[j]){
                ans[j] = (mid>>j)%2;
            }
        }
    }
    int x = 0;
    forn(i, 18){
        if(ans[i] != 0){
            x += power(2, i);
        }
    }
    cout << x << endl;
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

