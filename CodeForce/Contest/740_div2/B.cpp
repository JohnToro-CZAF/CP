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
    int a,b;
    cin >> a >> b;
    int n = a+b;
    set<int> s;
    if(n % 2 == 0){
        int cnt = 0;
        for(int i = max(a,b)-n/2; i <= n-(max(a,b)-n/2); i+=2){
            cnt++;
        }
        if(cnt == 0){
            cout << cnt << endl;
            return;
        }
        cout << cnt << endl;
        for(int i = max(a,b)-n/2; i <= n-(max(a,b)-n/2); i+=2){
            cout << i << " ";
        }
        cout << "\n";
        return;
    } else {
        int cnt = 0;
        for(int i = max(a,b)-n/2; i<= n-(max(a,b)-n/2); i++){
            s.insert(i);
        }
        for(int i = max(a,b) - (n+1)/2; i<= n-(max(a,b)-(n+1)/2); i++){
            s.insert(i);
        }
        cnt = s.size();
        if(cnt == 0){
            cout << cnt << endl;
            return;
        }
        cout << cnt << endl;
        for(auto x : s){
            cout << x << " ";
        }
        cout << "\n";
        return;
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
