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
const ll mod = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
vector<ll> adj[(1<<20)];
void solve(){
    ll n,m,i,j,s0,x;
    cin >> m >> n;
    cin >> s0;
    ll a[n],b[n],dis[m];
    bool used[m];
    for(i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            x=(i*a[j]+b[j])%m;
            adj[i].push_back(x);
        }
        used[i]=false;
        dis[i]=INF;
    }
    queue<ll> q;
    q.push(s0);
    used[s0]=true;
    dis[s0]=0;
    while(!q.empty()){
        auto u=q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!used[v]){
                dis[v]=dis[u]+1;
                used[v]=true;
                q.push(v);
            }
        }
    }
    if(dis[0]==INF){
        cout << -1 << "\n";
    }
    else{
        cout << dis[0] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    c=1;
 //   cin >> c;
    while(c--){
        solve();
    }
}

