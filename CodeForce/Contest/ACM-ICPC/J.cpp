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
    int n, m;
    cin >> n >> m;
    vi b(n), p(m);
    forn(i, n){
        cin >> b[i];
    }
    forn(i, m){
        cin >> p[i];
    }

    set<int> can_weight;
    forn(bm, (1 << m)){
        ll s = 0;
        forn(dg, m){
            if ((bm >> dg) & 1) s += p[dg];
        }
        // if (bm == 5){
        //     cout << bm << ": ";
        //     forn(dg, m) cout << ((bm >> dg) & 1) << "";
        //     cout << ": ";
        //     cout << s << "\n";
        // }
        int max_bm2 = (1 << m) - 1 - bm;
        bool flag = false;
        forn(bm2, (1 << m)){
            ll s2 = 0;
            if (max_bm2 < (bm2 | max_bm2)) continue;
            forn(dg, m){
                if ((bm2 >> dg) & 1) s2 += p[dg];
            }
            // if (bm == 5 && (max_bm2 == (bm2 | max_bm2))){
            //     cout << bm2 << ": ";
            //     forn(dg, m) cout << ((bm2 >> dg) & 1);
            //     cout << ": ";
            //     cout << s2 << "\n";
            // }
            if (s2 == s){
                flag = true;
                break;
            }    
        }

        if (flag) can_weight.insert(s);
    }

    set<int> ans;
    // for (int w: can_weight) cout << w << " ";
    for (int x: b){
        for (int y: can_weight) ans.insert(x + 2 * y);
    }
    for (int x: ans) cout << x << " ";
    cout << "\n";
    // cout << ans.size();
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

