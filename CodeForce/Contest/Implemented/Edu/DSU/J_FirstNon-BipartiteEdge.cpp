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

vector<int> parent, rang, dis;

void make_set(int v) {
    parent[v] = v;
    rang[v] = 0;
    dis[v] = 0;
}

pii find_set(int v) {
    if (v == parent[v])
        return {v, dis[v] = 0};
    pii p = find_set(parent[v]);
    parent[v] = p.first;
    dis[v] = (dis[v]+p.second)%2;
    return {p.first, dis[v]};
}

void union_sets(int a, int b) {
    pii a1 = find_set(a);
    pii b1 = find_set(b);
    if (a != b) {
        if (rang[a1.first] < rang[b1.first])
            swap(a1.first, b1.first);
        parent[b1.first] = a1.first;
        dis[b1.first] = (1+a1.second+b1.second)%2;
        if (rang[a1.first] == rang[b1.first])
            rang[a1.first]++;
    } else{
        return;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    int shift = 0;
    parent.resize(n);
    rang.resize(n);
    dis.resize(n);
    forn(i, n){
        make_set(i);
    }
    int index = 0; bool run = false;
    forn(i, m){
        int x, y; cin >> x >> y;
        x--; y--;
        pii x1 = find_set(x);
        pii y1 = find_set(y);
        if(x1.first != y1.first){
            union_sets(x, y); 
        } else {
            if(dis[x]%2 == dis[y]%2 && !run){
                index = i;
                run = true;
            }
        }
    }
    if(run){
        cout << index + 1 << endl;
    } else {
        cout << -1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

