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
const int maxp = maxn;

void solve(){
    int n;
    cin >> n;
    map<int, int> deg;
    vii req(n-1);
    forn(i, n-1){
        int x, y;
        cin >> x >> y;
        req[i] = make_pair(x, y);
        deg[x]++;
        deg[y]++;
    }
    int cnt = 0;
    if(n==2){
        cout << 2 << endl;
        return;
    }
    for(auto [r, f] : deg){
        if(deg[r] >= 2){
            cnt++;
        }
    }
    if(cnt >= 3){
        cout << -1 << endl;
        return;
    }
    if(cnt == 1){
        int that;
        for(auto [r, f] : deg){
            if(deg[r] >= 2){
                that = r;
            }
        }
        vi ans(n-1, 3);
        forn(i, n-1){
            if(req[i].second == that || req[i].first == that){
                ans[i] = 2;
                break;
            }
        }
        forn(i, n-1){
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    int x, y;
    int t = 0;
    for(auto [r, f] : deg){
        if(deg[r] >= 2 && t == 0){
            x = r;
            t++;
        } else if(deg[r] >= 2 && t == 1) {
            y = r;
            break;
        }
    }
    vi ans(n-1, 3);
    forn(i, n-1){
        if((req[i].first == x && req[i].second == y) || (req[i].first == y && req[i].second == x)){
            ans[i] = 2;
            break;
        }
    }
    forn(i, n-1){
        cout << ans[i] << " "; 
    }
    cout << endl;
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

