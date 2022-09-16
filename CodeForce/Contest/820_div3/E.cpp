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
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
typedef vector<vector<ll> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(ll i=l;i<=r;++i)
#define per(i,r,l) for(ll i=r;i>=l;--i)
#define rep0(i,l,r) for(ll i=l;i<r;++i)
#define forn(i,n) for(ll i=0;i<n;++i)
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

const ll MAXN = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
int n, t[4*MAXN];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = (t[v*2] + t[v*2+1]) % 9;
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return (sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r)) % 9;
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = (t[v*2] + t[v*2+1])%9;
    }
}
bool cmp(pair<int,int> a, pair<int, int> b){
    if(a.first < b.first){
        return true;
    } else if (a.first > b.first){
        return false;
    } else {
        if(a.second < b.second){
            return true;
        } else if(a.second > b.second){
            return false;
        } else {
            return true;
        }
    }
}

void solve(){
    mem(t, 0);
    string s;
    cin >> s;
    int w, m;
    cin >> w >> m;
    n = s.length();
    // tong cac chu so % 9 = so du cua no
    int v[n];
    mem(v, 0);
    int tempsum = 0;
    forn(i, n){
        v[i] = s[i] - '0';
        // cout << v[i] << " ";
    }
    // cout << endl;
    build(v, 1, 0, n-1);
    map<int, vi> a1;
    for(int i = 0; i+w-1 < n; i++){
        int q = sum(1, 0, n-1, i, i+w-1);
        // cout << "start" << endl;
        // cout << i << " " << q << endl;
        a1[q].push_back(i);
        // cout << q << " " << i << endl;
    }
    for(auto& [k, tempvec] : a1){
        while(tempvec.size() > 2){
            tempvec.pop_back();
        }
    }
    map<pair<int, int>, int> ready;
    map<pair<int,int>, pair<int, int> > ans;
    for(int k = 0; k < 9; k++){
        for(int i = 0; i < 9; i++){
            for(int x = 0; x < 9; x++){
                for(int y = 0; y < 9; y++){
                    if(x == y) {
                        if(a1[x].size() < 2) continue;
                        if((x*i + y) % 9 == k){
                            if(ready[make_pair(i, k)]){
                                continue;
                            } else {
                                ans[make_pair(i, k)] = make_pair(a1[x][0], a1[y][1]);
                                ready[make_pair(i, k)] = 1;
                            }
                        }  
                        continue;                      
                    }
                    if(a1[x].size() > 0 && a1[y].size() > 0){
                        if((x*i + y) % 9 == k){
                            if(ready[make_pair(i, k)]){
                                continue;
                            } else {
                                ans[make_pair(i, k)] = make_pair(a1[x][0], a1[y][0]);
                                ready[make_pair(i, k)] = 1;
                            }
                        }
                    }
                }
            }
            if(!ready[make_pair(i, k)]){
                ans[make_pair(i, k)] = make_pair(-1, -1);
            } else {
                // cout << i << " " << k << " " << ans[make_pair(i, k)].first << " " << ans[make_pair(i, k)].second << endl;
            }
        }
    }
    // cout << sum(1, 0, n-1, 0, 1) << endl;
    while(m--){
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--;
        int q = sum(1, 0, n-1, l, r);
        // cout << "qe" << q << endl;
        pair<int, int> temp = ans[make_pair(q, k)];
        if(temp.first != -1){
            cout << temp.first + 1 << " " << temp.second + 1 << endl;
        } else {
            cout << -1 << " " << -1 << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll c;
    cin >> c;
    while(c--){
        solve();
    }
}


