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
    int n, q;
    cin >> n >> q;
    vi a(n);
    for(int& x : a){cin >> x; x--;}
    vi b = a;
    reverse(all(b));
    vector<vi> won = vvi(n, vi());
    for(int i = 0; i < n; i++){
        int s = b.size();
        if(b[s-1] == n-1 || b[s-2] == n-1){
            won[n-1].push_back(i+1);
            continue;
        }
        if(b[s-1] > b[s-2]){
            won[b[s-1]].push_back(i+1);
            swap(b[s-1], b[s-2]);
        } 
        else {
            won[b[s-2]].push_back(i+1);
        }
        b.pop_back();
    }
    while(q--){
        int i, k; cin >> i >> k;
        i--;
        if(won[a[i]].size() == 0 || k < won[a[i]][0]){
            cout << 0 << endl;
        } else {
            int idx;
            auto it = lower_bound(all(won[a[i]]), k);
            if(it == won[a[i]].end()){
                idx = won[a[i]].size();
                idx--;
            } else {idx = it - won[a[i]].begin();}
            if(a[i] == n-1){
                cout << idx + 1 + max(k-n, 0) << endl;
            } else {
                cout << idx + 1 << endl;
            }
        }
    }

    // vi v = {1, 3, 4, 6, 7};
    // int idx = lower_bound(all(v), 1) - v.begin();
    // cout << idx << endl;
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

