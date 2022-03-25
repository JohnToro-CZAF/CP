#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i);
#define per(i,r,l) for(int i=r;i>=l;--i);
#define rep0(i,l,r) for(int i=l;i<r;++i);
#define forn(i,n) for(int i=0;i<n;++i);
#define all(a) (a).begin(), (a).end();
#define allr(a) (a).rbegin(), (a).rend();
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++);
#define mem(a,b) memset(a, (b), sizeof(a));
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

void solve(){
    int n, m;
    cin >> n >> m;
    char c[n][m];
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < m; j++){
            c[i][j] = s[j];
        }
    }
    bool flag = true;
    int index = 0;
    for(int i = 0; i < m; i++){
        for(int x = 0; x < n; x++){
            for(int y = x+1; y < n; y++){
                if(c[x][i] != c[y][i]){
                    index  = x;
                    flag = false;
                    break;
                }
            }
        }
    }
    bool chk = false;
    // cout << index << endl;
    if(flag){
        for(int i = 0; i < m; i++){
            cout << c[0][i];
        }
        cout << "\n";
        return;
    } else {
        for(int i = 0; i < m; i++){
            for(char d = 'a'; d <= 'z'; d++){
                char temp = c[index][i];
                c[index][i] = d;
                bool flag = true;
                for(int j = 0; j < n; j++){
                    int cnt = 0;
                    if(j == index) continue;
                    for(int x = 0; x < m; x++){
                        if(c[j][x] != c[index][x]) cnt++;
                    }
                    if(cnt > 1) flag = false;
                }
                if(flag){
                    for(int i = 0; i < m; i++){
                        cout << c[index][i];
                    }
                    cout << "\n";
                    return;
                }
                c[index][i] = temp;
            }
        }
        cout << -1 << endl;
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

