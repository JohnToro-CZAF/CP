#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vlll;
typedef vector<vector<ll> > vvl;
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
const ll INF = 1e18+2;

vvl edge;
vll val;
vlll order_cuop;
bool visited[maxn];
int n,k;
vector<vlll> com;
bool check(int sec){
    int cnt = 0;
    forn(i, int(order_cuop.size())){
        if(order_cuop[i].first <= sec) cnt++;  
    }
    sec = sec+1;   
    if(sec+cnt >= order_cuop.size()){
        return true;
    }
    return false;
}

pll bfs(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    com[s].push_back(make_pair(val[s], s));
    while(!q.empty()){
        ll top = q.front();
        q.pop();
        for(auto u : edge[top]){
            if(!visited[u]){
                visited[u] = true;
                com[s].push_back(make_pair(val[u], u));
                q.push(u);
            }
        }
    }
    sort(all(com[s]));
    return *com[s].begin();
}

void solve(){
    cin >> n >> k;
    edge = vvl(n, vector<ll>());
    val = vll(n);
    com = vector<vlll>(n, vlll());
    order_cuop.clear();
    map<ll, vlll> horizontal;
    map<ll, vlll> vertical;
    set<ll> hor;
    set<ll> ver;
    ll ma = 0;
    forn(i, n){
        ll x, y, value;
        cin >> x >> y >> value;
        horizontal[x].push_back(make_pair(y, i));
        vertical[y].push_back(make_pair(x, i));
        hor.insert(x);
        ver.insert(y);
        val[i] = value;
        ma = max(ma, value);
    }
    for(auto x : hor){
        sort(all(horizontal[x]));
        int i = 0;
        while(i != int(horizontal[x].size())){
            while(i < int(horizontal[x].size())-1 && horizontal[x][i+1].first - horizontal[x][i].first <= k){
                edge[horizontal[x][i].second].push_back(horizontal[x][i+1].second);
                edge[horizontal[x][i+1].second].push_back(horizontal[x][i].second);
                i++;
            }
            i++;
        }
    }
    for(auto y : ver){
        sort(all(vertical[y]));
        int i = 0;
        while(i != int(vertical[y].size())){
            while(i < int(vertical[y].size())-1 && vertical[y][i+1].first - vertical[y][i].first <= k){
                edge[vertical[y][i].second].push_back(vertical[y][i+1].second);
                edge[vertical[y][i+1].second].push_back(vertical[y][i].second);
                i++;
            }
            i++;
        }
    }
    mem(visited, false);
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            order_cuop.push_back(bfs(i));
        }
    }
    sort(all(order_cuop));
    int low = 0, high = ma, res = 0;
    while(low <= high){
        int mid = (low+high)>>1;
        if(check(mid)){
            high = mid-1;
            res = mid;
        } else{
            low = mid+1;
        }
    }
    cout << res << endl;
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

