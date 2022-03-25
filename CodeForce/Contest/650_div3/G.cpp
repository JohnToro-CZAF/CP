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
#include<stack>
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
    int n;
    cin >> n;
    stack<int> s;
    vii v;
    vi a(n);
    forn(i, n){
        cin >> a[i];
        v.push_back(make_pair(a[i], i));
    }
    sort(all(v));
    v.push_back(make_pair(-1, -1));
    int it = 0;
    int i = 0;
    while(i < n){
        a[v[i].second] = it;
        while(v[i].first == v[i+1].first){
            a[v[i+1].second] = it;
            i++;
        }
        it++;
        i++;
    }
    vvi pos(n);
    forn(i, n){
        pos[a[i]].push_back(i);
    }
    forn(i, n){
        cout << a[i] << " ";
    }
    cout << endl;
    vi dp(n, 1);
    vi dpfirst(n), dplast(n);
    forn(i, n){
        dpfirst[i] = a[i];
        dplast[i] = a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; a[i] >= 1 && j < pos[a[i]-1].size(); j++){
            if(a[i] >= 1 && pos[a[i]-1][j] >= i){
                break;
            } else if(a[i] >= 1 && pos[a[i]-1][j] < i){
                if(pos[a[i]][0] > pos[a[i]-1][j]){
                    dp[i] = dp[pos[a[i]-1][j]] +1;
                    // dpfirst[i] = a[pos[a[i]-1][j]];
                }
            }
        }
        for (int j = 0; j < pos[a[i]].size(); j++){
            if(pos[a[i]][j] >= i){
                break;
            } else if(pos[a[i]][j] < i){
                if(dp[pos[a[i]][j]] + 1 > dp[i]){
                    dp[i] = dp[pos[a[i]][j]]+1;
                }
            }
        }
    }
    forn(i, n){
        cout << dp[i] << " ";
    }
    cout << endl;
    int m = 0;
    forn(i, n){
        // cout << ans[i] << endl;
        m = max(m, dp[i]);
    }
    cout << n - m << endl;
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

