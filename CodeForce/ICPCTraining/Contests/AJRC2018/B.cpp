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
    ll ha, hb, aa, ab;
    cin >> ha >> hb >> aa >> ab;
    ll hab = ha + hb;
    ll tot = 0;
    ll cp;
    for (ll i = 1; i <= maxn; i++){
        tot += i;
        if (tot > hab + hb){
            cp = i;
            break;
        }
    }

    ll cost;
    vector<tuple<int, int, int, ll>> best;

    ll ans = cp * (aa + ab);
    ll r = cp;
    ll tota = 0;
    ll tott = tot;
    for (ll i = 1; i <= cp; i++){
        tota += i;
        if (tota < ha) continue;
        ll thistota;
        if (i > ha) thistota = i;
        else thistota = tota;
        ll remainb = hb - (thistota - ha);
        // cout << i << " " << thistota << " " << remainb << "\n";   
        while (tott - thistota >= remainb){
            cost = i * aa + r * ab;
            if (cost < ans){
                ans = cost;
                best.clear();
                best.push_back({0, i, r, thistota - ha});
            }
            else if (cost == ans){
                best.push_back({0, i, r, thistota - ha});
            }
            else{

            }
            if (tott - thistota - r < remainb) break;
            tott -= r;
            r--;
        }
        // cout << r << " " << ans << "\n";
    }

    r = cp;
    ll totb = 0;
    tott = tot;
    for (ll i = 1; i <= cp; i++){
        totb += i;
        if (totb < hb) continue;
        ll thistotb;
        if (i >= hb) thistotb = i;
        else thistotb = totb;
        ll remaina = ha - (thistotb - hb);
        // cout << i << " " << totb << " " << remaina << "\n";   
        while (tott - thistotb >= remaina){
            cost = i * ab + r * aa;
            if (cost < ans){
                ans = cost;
                best.clear();
                best.push_back({1, i, r, thistotb - hb});
            }
            else if (cost == ans){
                best.push_back({1, i, r, thistotb - hb});
            }
            else{
            }

            if (tott - thistotb - r < remaina) break;
            tott -= r;
            r--;
        }
    }

    cout << ans << " ";
    for (auto x: best){
        int last = get<0>(x);
        int first_kill = get<1>(x);
        int last_kill = get<2>(x);
        ll hp_for_first = get<3>(x);

        // for (int i = 1; i <= first_kill; i++){
        //     if (hp_for_first - 1ll * i - 1ll * (first_kill - i) > 0){

        //     }
        // }

        if (last == 0){
            forn(i, first_kill) cout << "A";
            forn(i, last_kill - first_kill) cout << "B";
        }
        if (last == 1){
            forn(i, first_kill) cout << "B";
            forn(i, last_kill - first_kill) cout << "A";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    // cout << c << "\n";
    while(c--){
        solve();
    }
}

