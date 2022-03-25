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
const char min_char = '0';
void solve(){
    int n, m;
    cin >> n >> m;
    string s;
    vs v(n);
    forn(i, n){
        cin >> v[i];
    }
    cin >> s;
    pair<pii, int> bad = {{-1,-1}, -1};
    pair<pii, int> dp2[10][10], dp3[10][10][10];
    forn(i, 10){
        forn(j, 10){
            dp2[i][j] = bad;
            forn(k, 10){
                dp3[i][j][k] = bad;
            }
        }
    }
    forn(i, n){
        forn(j, m){
            if(j+1 < m){
                dp2[v[i][j]-min_char][v[i][j+1]-min_char] = {{j, j+1}, i};
            }
            if(j+2 < m){
                dp3[v[i][j]-min_char][v[i][j+1]-min_char][v[i][j+2]-min_char] = {{j, j+2}, i};
            }
        }
    }
    vi last(m+1, -1);
    last[0] = 0;
    forn(i, m){
        if(last[i] == -1) continue;
        if(i+1 < m && dp2[s[i]-min_char][s[i+1]-min_char] != bad){
            last[i+2] = i;
        }
        if(i+2 < m && dp3[s[i]-min_char][s[i+1]-min_char][s[i+2]-min_char] != bad){
            last[i+3] = i;
        }
    }
    if(last[m] == -1){
        cout << -1 << endl;
        return;
    }
    vector<pair<pii, int> > ans;
    int it = m;
    while(it > 0){
        if(last[it] == it-2){
            it -= 2;
            ans.push_back(dp2[s[it]-min_char][s[it+1]-min_char]);
        } else {
            it -= 3;
            ans.push_back(dp3[s[it]-min_char][s[it+1]-min_char][s[it+2]-min_char]);           
        }
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    forn(i, int(ans.size())){
        cout << ans[i].first.first+1 << " " << ans[i].first.second+1 << " " << ans[i].second+1 << endl;
    }
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

