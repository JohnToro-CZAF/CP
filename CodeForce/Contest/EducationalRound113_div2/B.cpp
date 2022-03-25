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
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    char c[n][n];
    int cnt = 0;
    forn(i, n){
        if(s[i] == '2')cnt++;
    }
    if(cnt == 1 || cnt == 2){
        cout << "NO" << endl;
        return;
    }
    vi v;
    forn(i, n){
        forn(j, n){
            if(i == j){
                c[i][j] = 'X';
                continue;
            }
            c[i][j] = '=';
        }
    }
    forn(i, n){
        if(s[i] == '1'){
            for(int j = 0; j < n; j++){
                if(i == j){c[i][j] = 'X'; continue;}
                else {
                    c[i][j] = '=';
                    c[j][i] = '=';
                }
            }
        }
        if(s[i] == '2'){
            v.push_back(i);
        }
    }
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }
    // cout << "\n";
        // cout << "loz" << endl;
    int k = int(v.size());
    // cout << k << endl;
    for(int i = 0; i < k-1; i++){
        c[v[i]][v[i+1]] = '+';
        c[v[i+1]][v[i]] = '-';
    }
    if(k > 0){
        c[v[0]][v[k-1]] = '-';
        c[v[k-1]][v[0]] = '+';
    }
    cout << "YES" << endl;
    forn(i, n){
        forn(j, n){
            cout << c[i][j];
        }
        cout << "\n";
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

