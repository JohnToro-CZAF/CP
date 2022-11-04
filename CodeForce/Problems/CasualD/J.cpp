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
#include <stack>
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

int n;
vi p(maxn);
vi a(maxn); // permutations
vvi adj(maxn);
vi ans;

int keep = 1;
void dfs(int s, int p){
    for(int v : adj[s]){
        // cout << v << " ";
        if(v != p) continue;
        dfs(v, s);
    }
    a[s] = keep++;
    cout << keep << " ";
    // cout << a[s] << " ";
}

void dfs1(int s, int p){
    int cur_min = a[s];
    for(int v : adj[s]){
        if(v != p) continue;
        dfs(v, s);
        cur_min = min(cur_min, a[v]);
    }
    a[s] = cur_min;
    ans.push_back(cur_min);
}

void solve(){
    cin >> n;
    keep = 1;
    adj = vvi(n, vi());
    p.resize(n);
    a.resize(n);
    forn(i, n-1){
        cin >> p[i+1];
        // cout << p[i+1] << " ";
        adj[--p[i+1]].push_back(i+1);
    }
    forn(i, n){
        for(int v : adj[i]){
            cout << v << " ";
        }
    }
    // dfs(0, -1);
    // dfs1(0, 0);
    // cout << "ok" << endl;
    // forn(i, n){
    //     cout << ans[i] << " ";
    // }
    stack<int> st;
    st.push(0);
    for(int i = 0; i < n; i++){
        int top = st.top();
        if(ans[i] >= top){
            st.push(ans[i]);
        }
    }
    // cout << int(st.size()) - 1 << endl;
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

