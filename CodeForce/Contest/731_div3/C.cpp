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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

vi dis;
vvi edge;
vi enemy;
bool bfs(int s, int n){
    vector<bool> visited(n, false);
    dis = vi(n, 0);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int t = q.front();
        visited[t] = true;
        q.pop();
        // cout << t << " ";
        for(int u : edge[t]){
            if(!visited[u]){
                dis[u] = dis[t]+1;
                q.push(u);
            }
        }
    }
    int m = dis[0];
    int M = INF;
    for(auto v : enemy){
        M = min(M, dis[v]);
    }
    if(m < M){
        return true;
    }
    return false;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vi exit;
    edge = vvi(n, vector<int>());
    enemy.clear();
    forn(i, k){
        int x;
        cin >> x;
        --x;
        enemy.push_back(x); 
    }
    forn(i, n-1){
        int x, y;
        cin >> x >> y;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    forn(i, n){
        if(i == 0) continue
        if(edge[i].size() == 1) exit.push_back(i);
    }
    bool flag = false;
    for(auto u : exit){
        if(bfs(u, n)){flag = true; break;}
    }
    cout << (flag?"YES":"NO") << endl;
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

