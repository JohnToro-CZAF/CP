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
#define forn(i,n) for(int i=1;i<=n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}


const int maxn = 1e6+3;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

vi sortedCnt;
vvi adj(maxn);
vector<vector<pair<pair<int, int>, int> > >res(maxn);

int n, q;
int a[maxn];
int ans[maxn];
int first[maxn];
int last[maxn];
int pos[maxn];
vi cop;

void dfs(int s, int prev){
    // before enter
    cout << "before" << endl;
    for(auto x : sortedCnt){
        cout << x << " "; 
    }
    cout << endl;
    for(auto x : cop){
        cout << x << " ";
    }
    cout << endl;
    int x = a[s];
    int lastEqual = last[sortedCnt[pos[s]]]; // index of last equal value
    int y = cop[lastEqual]; // the number at index last equal
    last[sortedCnt[pos[s]]] = lastEqual-1;
    // cout << pos[s] << " " << pos[lastEqual] << endl;
    swap(cop[lastEqual], cop[pos[s]]);
    swap(sortedCnt[lastEqual], sortedCnt[pos[s]]);
    swap(pos[lastEqual], pos[s]);
    // cout << pos[lastEqual] << " " << pos[s] << endl;
    first[++sortedCnt[pos[s]]] = pos[s];
    last[sortedCnt[pos[s]]] = pos[s];
    cout << "done" << endl;
    for(auto x : sortedCnt){
        cout << x << " "; 
    }
    cout << endl;
    for(auto x : cop){
        cout << x << " ";
    }
    cout << endl;
    // processing
    for(auto triple : res[s]){
        pair<int, int> p = triple.first;
        int order = triple.second;
        auto it = upper_bound(sortedCnt.begin(), sortedCnt.end(), p.first);
        if(it != sortedCnt.end()){
            int index = upper_bound(sortedCnt.begin(), sortedCnt.end(), p.first) - sortedCnt.begin();
            int k = p.second;
            if(k + index >= n) ans[order] = -1;
            else {ans[order] = cop[k+index];}
        } else {
            ans[order] = -1;
        }
    }
    for(auto x : adj[s]){
        if(x == s) continue;
        dfs(x, s);
    }
    // after enter
    int firstEqual = first[sortedCnt[pos[s]]]; // index of last equal value
    first[sortedCnt[pos[s]]] = firstEqual-1;
    // cout << pos[s] << " " << pos[lastEqual] << endl;
    swap(cop[firstEqual], cop[pos[s]]);
    swap(sortedCnt[firstEqual], sortedCnt[pos[s]]);
    swap(pos[lastEqual], pos[s]);
    // cout << pos[lastEqual] << " " << pos[s] << endl;
    last[--sortedCnt[pos[s]]] = pos[s];
    last[sortedCnt[pos[s]]] = pos[s];
}

void solve(){
    cin >> n >> q;
    // reset
    forn(i, n){
        adj[i].clear();
        res[i].clear();
    }
    sortedCnt.assign(n+1, 0);
    cop.assign(n+1, 0);
    mem(a, 0);
    // endreset
    forn(i, n){
        cin >> a[i];
        cop[i] = a[i];
        pos[i] = i;
    }
    int source = 1;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    forn(i, q){
        int v, l, k;
        cin >> v >> l >> k;
        res[v].push_back(make_pair(make_pair(l, k), i));
    }
    // setup the data structure
    first[0] = 1;
    last[0] = n;
    // end setup
    dfs(source, -1);
    for(int i = 0; i < q; i++){
        cout << ans[i] << " "; 
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

