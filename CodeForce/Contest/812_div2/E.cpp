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

vector<int> parent, rang;

void make_set(int v) {
    parent[v] = v;
    rang[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rang[a] < rang[b])
            swap(a, b);
        parent[b] = a;
        if (rang[a] == rang[b])
            rang[a]++;
    } else{
        return;
    }
}
void solve(){
    int n, m;
    vector<vector<int> > dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
    cin >> n >> m;
    parent.clear();
    rang.clear();
    parent.resize(n*m);
    rang.resize(n*m);
    vector<vector<int> > G(n, vector<int>(m, 0));
    string s[n];
    forn(i, n){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            G[i][j] = (s[i][j] == '*') ? 1 : 0;
        }
    }
    for(int i = 0; i < n*m; i++){
        make_set(i);
    }
    vector<pair<int,int> > edge;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(auto dir : dirs){
                if(i + dir[0] >= 0 && i + dir[0] < n && j + dir[1] >= 0 && j + dir[1] < m){
                    if(G[i][j] == G[i+dir[0]][j+dir[1]] && G[i][j] == 1){
                        edge.push_back(make_pair((i+dir[0])*m + j+dir[1], i*m+j));                     
                    }
                }
            }
        }
    }
    for(auto e : edge){
        if(find_set(e.first) != find_set(e.second)){
            union_sets(e.first, e.second);
        }
    }
    vector<vector<int> > tup(n*m, vector<int>());
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(G[i][j] == 1){
                int x = find_set(i*m + j);
                // cout << x << " ";
                tup[x].push_back(i*m + j);
            }
        }
    }

    for(int i = 0; i < m*n; i++){
        if(tup[i].size() == 0){
            continue;
        }
        if(tup[i].size() != 3){
            cout << "NO" << endl;
            return;
        } else {
            set<int> x, y;
            for(auto t : tup[i]){
                x.insert(t/m); y.insert(t%m);
            }   
            if(x.size() == 3 || y.size() == 3){
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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

