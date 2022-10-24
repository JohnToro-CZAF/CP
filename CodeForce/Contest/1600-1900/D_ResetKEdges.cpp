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

const char min_char = 'a';
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

int n, k;
vector<bool> used;
vi st;
vi pd;
vvi adj;

void dfs(int s){
    used[s] = true;
    for(int v : adj[s]){
        if(used[v]) continue;
        dfs(v);   
    }
}

void init(int v, int d){
    st.push_back(v);
    if((int)st.size() - d >= 0){
        pd[v] = st[int(st.size())-d];
    }
    for(int u : adj[v]){
        init(u, d);
    }
    st.pop_back();
}

int check(int d){

    st.clear();
    pd.assign(n, -1);
    init(0, d);
    used.assign(n, false);
    vi ord, h(n);

    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        ord.push_back(v);
        for(int u : adj[v]){
            h[u] = h[v] + 1;
            q.push(u);
        }
    }
    int res = 0;
    reverse(all(ord));
    for(int v : ord){
        if(!used[v] && h[v] > d){
            dfs(pd[v]);
            res++;
        }
    }
    return res;
}

void solve(){
    cin >> n >> k;
    vi p = vi(n);
    adj = vvi(n, vi());
    forn(i, n-1){
        int p; cin >> p; p--;
        adj[p].push_back(i+1);
    }

    int l = 1, r = n-1, m = n;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid) <= k){
            r = mid-1;
            m = mid;
        } else {
            l = mid+1;
        }
    }
    cout << m << endl;
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

