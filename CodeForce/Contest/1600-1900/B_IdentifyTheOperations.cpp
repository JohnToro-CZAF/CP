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
const ll MOD = 998244353;
const ll INF = 1e9;
const char min_char = 'a';

struct dsu {
    vector<int> parent, rang, mx, mi;

    dsu(int n){
        parent.resize(n+3);
        rang.resize(n+3);
        mx.resize(n+3);
        mi.resize(n+3);
        forn(i, n+3){
            make_set(i);
        }
    }

    void make_set(int v) {
        parent[v] = v;
        rang[v] = 0;
        mi[v] = v;
        mx[v] = v;
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[a] = b;
        } else{
            return;
        }
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n), b(m), pos(n+1);
    dsu right(n);
    dsu left(n);
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
        s.insert(b[i]);
    }
    ll ans = 1ll;
    for(int i = 0; i < m; i++){
        int j = pos[b[i]];
        if(j > 0 && j < n-1){
            // consdier the case n=1
            if(s.lower_bound(b[j+1]) != s.end() && s.lower_bound(b[j-1]) != s.end()){
                cout << 0 << endl;
                return;
            }
            if(s.lower_bound(b[j+1] != s.end())) {
                if(right.find_set(j+1) != right.find_set(j+2)){
                    right.union_sets(j+1, j+2);
                }
                if(left.find_set(j+1) != left.find_set(j)){
                    left.union_sets(j+1, j);
                }
                ans *= 2;
                ans %= MOD;
            }
            if(s.lower_bound(b[j-1] != s.end())) {
                if(right.find_set(j-1) != right.find_set(j)){
                    right.union_sets(j-1, j);
                }
                if(left.find_set(j-1) != left.find_set(j-2)){
                    left.union_sets(j, j-2);
                }
                ans *= 2;
                ans %= MOD;
            }
        } else if(j == 0){
            if(s.lower_bound(b[j+1]) != s.end()){
                cout << 0 << endl;
                return;
            }
        } else {
            if(s.lower_bound(b[j-1]) != s.end()){
                cout << 0 << endl;
                return;
            }            
        }
        s.erase(b[i]);
    }
    cout << ans << endl;
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

