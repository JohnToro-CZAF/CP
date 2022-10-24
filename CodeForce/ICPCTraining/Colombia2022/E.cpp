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

const int maxn = 5e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

vvi adj(maxn);
vi par(maxn, -1), subtreesize(maxn, -1), ans(maxn, -1);
vvi chi(maxn);

void bfs(int u, int pos, int need){
    // cout << u << " " << pos << " " << need << "\n";
    int s = chi[u].size();
    if (s == 0){
        subtreesize[u] = 1;
        ans[pos+1] = u;
        return;
    }

    int mid;
    if (s % 2 == 0) mid = (s-1) / 2; 

    else{ 
        if (need == 1) mid = s / 2 - 1;
        else mid = (s-1) / 2;
    }

    int new_pos = pos;
    for (int i = 0; i <= mid; i++){
        bfs(chi[u][i], new_pos, 2);
        new_pos += subtreesize[chi[u][i]];
    }

    new_pos++;
    ans[new_pos] = u;
    for (int i = mid+1; i < s; i++){
        bfs(chi[u][i], new_pos, 1);
        new_pos += subtreesize[chi[u][i]];
    }
    subtreesize[u] = new_pos - pos;
}

void solve(){
    int n; cin >> n;

    if (n == 1){
        cout << 0;
        return;
    }

    forn(i, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    stack<int> st;
    st.push(0);

    while (!st.empty()){
        int u = st.top(); st.pop();
        for (int v: adj[u]){
            if (v == par[u]) continue;
            par[v] = u;
            chi[u].push_back(v);
            st.push(v);
        }
    }

    while (!st.empty()) st.pop();

    bfs(0, -1, 0);

    // forn(i, n) cout << subtreesize[i] << " ";
    // cout << "\n";
    forn(i, n) cout << ans[i] << " ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    // cin >> c;
    c = 1;
    while(c--){
        solve();
    }
}

