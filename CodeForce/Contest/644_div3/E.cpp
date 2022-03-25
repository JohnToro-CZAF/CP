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

int a[60][60];

bool chk(int x, int y){
    if(a[x+1][y] == 1 || a[x][y+1] == 1) return true;
    return false;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = (s[j] == '0') ? 0 : 1; 
        }
    }
    if(n==1){
        cout << "YES" << endl;
        return;
    }
    bool f = true;
    for(int i = n-2; i >= 0; i--){
        // if(chk(i, i)){
        //     for(int j = i-1; j >= 0; j--){
        //         if(!chk(i, j)) f = false;
        //     }
        //     for(int j = i-1; j >= 0; j--){
        //         if(!chk(j, i)) f = false;
        //     }
        // } else f = false;
        for(int j = n-2; j >= 0; j--){
            if(a[i][j] == 1){
                if(!chk(i, j)) f = false;
            }
        }
    }
    if(!f){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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

