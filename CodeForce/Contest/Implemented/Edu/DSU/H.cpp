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

vector<int> parent, rang, siz, old, point;
void make_set(int v) {
    parent[v] = v;
    rang[v] = 0;
    old[v] = -1;
    point[v] = 0;
}

pii find_set(int v) {
    if (v == parent[v])
        return {v, 0};
    pii p = find_set(parent[v]);
    parent[v] = p.first;
    point[v] += p.second;
    return {parent[v], point[v]};
}

void union_sets(int a, int b) {
    a = (find_set(a)).first;
    b = (find_set(b)).first;
    if (a != b) {
        if(rang[a] <= rang[b]){
            parent[a] = b;
            point[a] += 1-point[b];
        } else {
            // point[b]++;
            parent[b] = a;
            // int old = point[a];
            point[a] += 1-point[b];
            point[b] += -point[a];
        }
        if(rang[a] == rang[b]){
            rang[a]++;
        }
    } else{
        return;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    parent.resize(n);rang.resize(n); old.resize(n); point.resize(n);
    forn(i, n){make_set(i);}
    while(m--){
        int order; cin >> order;
        if(order == 1){
            int x, y; cin >> x >> y;
            x--; y--;
            if(find_set(x) != find_set(y)){
                union_sets(x, y);
            }
        } else {
            int x; cin >> x; x--;
            int u = find_set(x).first;
            // forn(i, n){
            //     cout << parent[i]+1 << " ";
            // }
            // cout << endl;
            // forn(i, n){
            //     cout << point[i] << " ";
            // }
            // cout << endl;
            cout << point[x] << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
}

