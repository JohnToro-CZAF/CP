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

const int maxn = 1e6+4;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

string s;

struct Node {
    int optimal;
    int open;
    int close;

    Node(int opt, int o, int c){
        optimal = opt; open = o; close = c;
    }
    Node(){
        optimal = 0; open = 0; close = 0;
    }
};

Node st[maxn*4];

Node operator+(const Node& left, const Node& right){
    Node res;
    int tmp = min(left.open, right.close);
    res.optimal = left.optimal + right.optimal + tmp * 2;
    res.open = left.open + right.open - tmp;
    res.close = left.close + right.close - tmp;
    return res;
}

void build(int id, int l, int r){
    if(l == r){
        if(s[l] == '(') st[id] = Node(0, 1, 0);
        // else if(r < s.length() && s[l] == ')') st[id] = Node(0, 0, 1);
        else st[id] = Node(0,0,1);
        return;
    }
    int mid = (l+r)>>1;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id] = st[id*2] + st[id*2+1];
}

Node query(int id, int l, int r, int u, int v){
    if(v < l || r < u){
        return Node(0, 0, 0);
    }
    if(u <= l && r <= v){
        return st[id];
    }

    int mid = (l+r) / 2;
    return query(id*2, l, mid, u, v) + query(id*2+1, mid+1, r, u, v);
}

void solve(){
    cin >> s;
    s = '*' + s;
    int n = s.size();
    build(1, 1, n);
    int q;
    cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        cout << query(1, 1, n, x, y).optimal << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}

