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
#include <stack>
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

inline int get(int a, int b){
    return abs(a-(a+b)/2);
}

int n, m;
vector<int> dir;
vi ans;

void cal(vii a){
    vii v;
    for (int i = 0; i < int(a.size()); ++i)
    {
        v.push_back(a[i]);
        if(dir[a[i].second]){
            v.push_back(make_pair(2*m-a[i].first, a[i].second));
        } else {
            v.push_back(make_pair(-a[i].first, a[i].second));
        }
    }
    sort(all(v));
    int l = int(v.size());
    vector<int> direction(l);
    // 0 means left 1 means right
    for(int i = 0; i < l ; i++){
        if(v[i].first < m && v[i].first > 0){
            direction[i] = dir[v[i].second];
        } else {
            direction[i] = 1^dir[v[i].second];
        }
    }
    for (int i = 0; i < l; ++i)
    {
        cout << v[i].first << " ";
    }
    cout << endl;
    for (int i = 0; i < l; ++i)
    {
        cout << direction[i] << " ";
    }
    cout << endl;
    stack<pair<int, int> > s;
    bool looped[n];
    mem(looped, false);
    for(int i = 0; i < l; i++){
        if(looped[v[i].second]) continue;
        if(!looped[v[i].second] && direction[i]){
            cout << v[i].first << endl;
            s.push(v[i]);
            continue;
        }
        if(!s.empty()){
            pii t = s.top();
            if(t.second == v[i].second) continue;
            s.pop();
            if(looped[t.second]){
                continue;
            }
        }
        if(!s.empty() && !direction[i]){
            pii t = s.top();           
            cout << t.first << endl;
            s.pop();
            ans[t.second] = (ans[v[i].second] = get(t.first, v[i].first));
            looped[t.second] = true;
            looped[v[i].second] = true;
        }
    }
}

void solve(){
    cin >> n >> m;
    ans = vi(n, -1);
    dir = vector<int>(n);
    vii a, b;
    forn(i, n){
        int x; cin >> x;
        (x % 2 == 0) ? a.push_back(make_pair(x, i)) : b.push_back(make_pair(x, i));
    }
    forn(i, n){
        char x; cin >> x;
        dir[i] = (x == 'R') ? 1 : 0;
    }
    cal(b);
    for(auto u : ans){
        cout << u << " ";
    }
    cout << endl;
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

