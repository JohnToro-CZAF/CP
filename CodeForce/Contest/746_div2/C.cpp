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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

vvi edge;
int xo[maxn];
int a[maxn];
set<int> remain;
bool chk = false;
int first;
int ans;
int source;

int dfs(int s, int prev, int mode = 1){
    if(mode == 2){remain.insert(s);}
    for(auto u : edge[s]){
        if(u == prev){continue;}
        else if(mode == 1 || mode == 3) {
            xo[s] ^= dfs(u, s, mode);
        } else {
            dfs(u, s, mode);
        }
    }
    // find the (nearest leaf) subtree that have xor = all tree
    if(mode == 3 && !chk){
        if(xo[s] == ans && s!=source){
            first = s;
            chk = true;
            return 0;
        }
    }
    return xo[s];
}

void delt(int s, int prev, int target){
    if(s == target){
        for(int i = 0; i < edge[s].size(); i++){
            if(edge[s][i] == prev){
                edge[s].erase(i+edge[s].begin());
            }
        }
        for(int j = 0; j < edge[prev].size(); j++){
            if(edge[prev][j] == s){
                edge[prev].erase(j+edge[prev].begin());
            }
        }
        return;
    }
    for(auto u : edge[s]){
        if(u==prev) continue;
        else delt(u, s, target);
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    chk = false;
    source = 0;
    mem(xo, 0);
    mem(a, 0);
    remain.clear();
    edge = vvi(n, vi());
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n-1){
        int x, y;
        cin >> x >> y;
        x--;y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    forn(i, n){
        xo[i] = a[i];
    }
    for(int i = 0; i < n; i++){
        if(edge[i].size() > 1){source = i; break;}
    }
    ans = dfs(source, -1); // calculate all xor first
    if(ans == 0){
        cout << "YES" << endl;
    } else {
        if(k == 2){
            cout << "NO" << endl;
            return;
        }
        forn(i, n){
            xo[i] = a[i]; // reset for the finding
        }
        dfs(source, -1, 3); // attempt to find subtree that is not entired the tree but equal to all xor
        if(!chk){
            cout << "NO" << endl;
            return;
        }
        delt(source, -1, first); // delete the edge with $first and its ancestor in dfs(from source)
        dfs(source, -1, 2); // all the vertices within remain subtree
        mem(xo, 0); // reset for the dfs again
        for(auto u : remain){
            xo[u] = a[u]; // set all the vertices within remain subtree 
        }
        dfs(source, -1); // calculated all xor in the subtree in remain subtree
        for(auto u : remain){
            if(xo[u] == ans && u != source){
                cout << "YES" << endl;
                return;
            } 
        }
        cout << "NO" << endl;
        return;
    }
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

