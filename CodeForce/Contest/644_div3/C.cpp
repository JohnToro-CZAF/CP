#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define forn(i, n) for(int i=0;i<int(n);++i);
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
    int n;
    cin >> n;
    int a[n];
    int cnto = 0;
    int cnte = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) cnte++;
        else cnto++;
    }
    if(cnto % 2 == 0 && cnte % 2 == 0){
        cout << "YES" << endl;
        return;
    }
    sort(a, a+n);
    int cnt = 0;
    for(int i = 0; i < n-1; i++){
        if(a[i+1] - a[i] == 1){
            cnt++;
        }
    }
    if(cnt >= 1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

