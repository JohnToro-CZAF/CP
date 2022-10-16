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
void solve(int c){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> t(n);
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> t[i];
    }
    cout << "case " << c << endl;
    if(n == 1){
        cout << a[0] << endl;
        return;
    }
    vector<pair<int, int> > pa(n);
    forn(i, n){
        pa[i] = make_pair(a[i], t[i]);
    }
    sort(all(pa));
    vector<ll> pref(n, 0);
    vector<ll> suff(n, 0);
    pref[0] = 0;
    suff[n-1] = n-1;
    ll mx = pa[0].second;
    for(int i = 1; i < n; i++){
        if(pa[i].second > mx){
            pref[i] = i;
            mx = pa[i].second;
        } else {
            pref[i] = pref[i-1];
        }
    }
    mx = pa[n-1].second;
    for(int i = n-2; i >= 0; i--){
        if(pa[i].second > mx){
            suff[i] = i;
            mx = pa[i].second;
        } else {
            suff[i] = suff[i+1];
        }
    }
    double best = INF;
    double bestans = 0.0;
    for(int i = 0; i < n-1; i++){
        int l = pref[i];
        int r = suff[i+1];
        double x0 = (double) (pa[l].first + pa[r].first) / 2;
        cout << "iter " << i << endl;
        cout << "cac" <<  l+1 << " " << r+1 << endl;
        std::cout << std::setprecision(6) << x0 << '\n';
        cout << max((abs(x0 - pa[l].first) + pa[l].second), (abs(x0 - pa[r].first) + pa[r].second)) << endl;
        if(max((abs(x0 - pa[l].first) + pa[l].second), (abs(x0 - pa[r].first) + pa[r].second)) < best){
            best = max((abs(x0 - pa[l].first) + pa[l].second), (abs(x0 - pa[r].first) + pa[r].second));
            bestans = x0;
        }
    }

    std::cout << std::setprecision(6) << bestans << '\n';
    forn(i, n){
        cout << pa[i].first << " ";
    }
    cout << endl;
    forn(i, n){
        cout << pa[i].second << " ";
    }
    cout << endl; 
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve(c);
    }
}

