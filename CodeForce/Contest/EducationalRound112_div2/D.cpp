#include <bits/stdc++.h>
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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
void solve(){
    int n, m;
    cin >> n >> m;
    int cost[6][n];
    mem(cost, 0);
    string s;
    cin >> s;
    string l[6] = {"abc", "bca", "cab", "cba", "bac", "acb"};
    string t[6] = {"","","","","",""};
    int cnt = 0;
    forn(i, 6){
        forn(j, n){
            t[i] += l[i][j%3];
        }
    }
    forn(i, 6){
        // cout << t[i] << endl;
        forn(j, n){
            if(s[j] != t[i][j]){
                cost[i][j] = 1;
            } else {
                cost[i][j] = 0;
            }
        }
    }
    int sum[6][n+2];
    forn(i, 6){
        int temp = 0;
        sum[i][0] = 0;
        forn(j, n){
            temp += cost[i][j];
            sum[i][j+1] = temp; 
        }
    }
    while(m--){
        int i, j;
        cin >> i >> j;
        ll ans = INF;
        forn(x, 6){
            ans = min(ans, (ll)sum[x][j]-sum[x][i-1]);
        }
        cout << ans << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

