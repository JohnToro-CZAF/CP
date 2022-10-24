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

const char min_char = 'a';
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

int n, k;
vvi adj;
vi depth;
vi dp;
int mx_idx;

void dfs(int s, int p){
    int cnt = 0;
    int mx = 0;
    for(int v : adj[s]){
        if(v == p) continue;
        dfs(v, s);
        
        cnt++;
    }
    if(cnt){
        
        // dp[depth[s]] += cnt;
    } else {
        dp[0]++;
    }
}


bool check(int d){
    // we check if we can achieve the height d only using k operations
    // 5 4 3 2 1
    // 5 4 3 1 0
    if(d == 0){

    }
    vi cp = dp;
    int cpk = k;
    int ptr = mx_idx;
    // When kill a subtree, we also have to update the parent's depth
    while(cpk > 0 && ptr >= 0){
        cpk -= cp[ptr];
        if(cpk < 0){
            break;
        }
        for(int i = 0; i <= ptr; i++){
            if(i <= ptr/2){
                cp[i] += cp[ptr];
            } else {
                if(i == ptr){
                    cp[i] = 0;
                    continue;
                }
                cp[i] -= cp[ptr];
            }
        }
        while(cp[ptr] == 0){
            ptr--;
        }
    }
    if(ptr <= d){
        return true;
    } else {
        return false;
    }
}

void solve(){
    cin >> n >> k;
    adj = vvi(n, vi());
    depth = vi(n, 0);
    dp = vi(n, 0);
    vi p(n);
    forn(i, n-1){
        cin >> p[i+1];
        p[i+1]--;
        adj[i+1].push_back(p[i+1]);
        adj[p[i+1]].push_back(i+1);
    }
    // subtree[i] = number of subtree that has depth i
    // Update the subtree array, select the desired 
    dfs(0, -1);
    forn(i, n){
        cout << dp[i] << " "; 
    }
    cout << endl;
    forn(i, n){
        if(depth[i] != 0){
            mx_idx = i;
        }
    }
    int l = 0, r = n-1, m = n-1;
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid-1;
            m = mid;
        } else {
            l = mid+1;
        }
    }
    cout << m << endl;
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

