#include <bits/stdc++.h>
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

const int maxn = 4e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

vvi edge(maxn);
vi ans;
set<int> cycle;
set<int> more;

void dfs(int s, vi &color, int type){
    if(type == 0) ans[s] = 1;
    color[s] = 1;
    for(int v : edge[s]){
        // cout << v << " ";
        if(color[v] == 0){
            dfs(v, color, type);
        } else if(!type){
            if(color[v] == 1){
                cycle.insert(v);
            } else {
                more.insert(v);
            }
        }
    }
    color[s] = 2;
    if(type == 1) ans[s] = 2;
    if(type == 2) ans[s] = -1;
}

void solve(){
    int n, m;
    cin >> n >> m;
    ans = vi(n+1);
    cycle.clear();
    more.clear();
    edge = vvi(n+1);
    forn(i, m){
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
    }
    vector<vector<int> > color(3, vector<int>(n+1));
    dfs(1, color[0], 0);
    for(auto u : more){
        dfs(u, color[1], 1);
    }
    // more does not means is infinite but if indefinite then it is more than one path
    // dfs the more first then dfs the infinity // overwrite the more by infinite
    for(auto u : cycle){
        dfs(u, color[2], 2);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i+1] << " ";
    }
    cout << "\n";
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

