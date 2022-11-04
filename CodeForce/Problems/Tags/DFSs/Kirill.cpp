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
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
void solve(){
    int n, m;
    cin >> n >> m;
    vvi adj = vvi(n, vi());
    vector<set<int>> mask(n);
    forn(i, m){
        int x, y; cin >> x >> y; x--; y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int n_fr; cin >> n_fr;
    vector<int> fr;
    forn(i, n_fr){
        int x; cin >> x; x--;
        fr.push_back(x);
        // check if vertex is contained by a friend and idx_fr;
    }
    int no_wo_cars; cin >> no_wo_cars;
    vi is_wo_cars(n_fr, 0);
    vvi wo_fr_ver(n, vi());
    vi wo_cars;
    forn(i, no_wo_cars){
        int x; cin >> x; x--;
        is_wo_cars[x] = 1;
        wo_cars.push_back(x);
        wo_fr_ver[fr[x]].push_back(i);
    }

    // BFS
    vector<int> dist(n, -1);
    queue<int> q;
    dist[0] = 0;
    mask[0].insert(0);
    q.push(0);
    vi mask_help(n, 0);
    forn(i, no_wo_cars){
        mask_help[fr[wo_cars[i]]] |= (1<<i);
    }
    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(int v : adj[top]){
            int idx;
            if(dist[v] == -1){
                dist[v] = dist[top] + 1;
                q.push(v);
                // if not met yet -> push
            }
            if(dist[v] == dist[top] + 1){
                // visit again but finite amount of time - 
                // depends on the number top that neighbour to v
                int local_msk = 0;
                for(int msk : mask[top]){
                    mask[v].insert(msk | mask_help[v]);
                }
            }
        }
    }
    bitset<65> backpack;
    bitset<65> temp = backpack;
    backpack[0] = 1;
    for(int f = 0; f < fr.size(); f++){
        if(is_wo_cars[f] == 1){
            continue;
        }
        int i = fr[f];
        temp = backpack; 
        forn(cur_msk, 1<<no_wo_cars){
            if(!backpack[cur_msk]) continue;
            for(int msk : mask[i]){
                temp[(cur_msk | msk)] = 1;
            }
        }
        backpack = temp; // not allow to mask themselves
    }
    int mx = no_wo_cars;
    forn(i, 1<<no_wo_cars){
        if(backpack[i]){
            int res = no_wo_cars - __builtin_popcount(i);
            mx = min(res, mx);
        }
    }
    cout << mx << endl;
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

