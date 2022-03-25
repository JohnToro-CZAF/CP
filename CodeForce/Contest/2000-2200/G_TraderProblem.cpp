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
const int INF = 1e9;
const char min_char = 'a';

void solve(){
    int n, m, q;
    map<int, vi> pos;
    cin >> n >> m >> q;
    vi a(n), b(m); ll cur = 0;
    forn(i, n){
        cin >> a[i];
        cur += a[i];
    }
    forn(i, m){
        cin >> b[i];
    }
    vi c = a; c.insert(c.end(), all(b));
    sort(all(a)); sort(all(b)); sort(all(c));
    int s = int(c.size());
    ///////////////////////////////////
    vi dif(s);
    vi mark(s);
    vi prefix(s+1, 0);
    vector<ll> prefixSum(s+1, 0);
    set<pii> segs;
    dif[0] = 0;
    int it = 0, it1 = 0;
    while(it < n){
        while(it1 < s && c[it1] != a[it]){
            it1++;
        }
        mark[it1] = 1;
        it1++;
        it++;
    }
    for(int i = 0; i < s; i++){
        prefixSum[i+1] = prefixSum[i] + c[i];
        prefix[i+1] = prefix[i] + mark[i];
    }
    for(int i = 1; i < s; i++){
        dif[i] = c[i]-c[i-1];
        pos[dif[i]].push_back(i-1);
    }
    forn(i, s){
        segs.insert(make_pair(i, i+1));
    }
    auto getSeg = [&](pii seg){
        int cnt = prefix[seg.second]-prefix[seg.first];
        return prefixSum[seg.second]-prefixSum[seg.second-cnt];
    };
    vector<pair<int, ll> > ans; ans.push_back(make_pair(0, cur));
    for(auto [r, v] : pos){
        for(int j : v){
            auto itr = segs.upper_bound(make_pair(j, int(1e9)));
            auto itl = prev(itr);
            pii pr = *itr; 
            pii pl = *itl;
            cur -= getSeg(pr);
            cur -= getSeg(pl);
            pii p = make_pair(pl.first, pr.second);
            cur += getSeg(p);
            segs.erase(pl);
            segs.erase(pr);
            segs.insert(p);
        }
        ans.push_back(make_pair(r, cur));
    }
    ///////////////////////////////////
    while(q--){
        int k; cin >> k;
        int it = upper_bound(all(ans), make_pair(k+1, -1ll)) - ans.begin() - 1;
        cout << ans[it].second << endl;
    } 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

