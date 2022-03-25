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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

void solve(){
    ll W,H;
    cin >> W >> H;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll w1, h1;
    w1 = abs(x2-x1);
    h1 = abs(y2-y1);
    ll w, h;
    cin >> w >> h;
    if(w1+w >W && h1+h> H){
        cout << -1 << endl; 
    } else {
        int leftOrRight;
        int downOrUp;
        if(x1 > W - x2) leftOrRight = 0;
        else leftOrRight = 1;
        if(y1 > H - y2) downOrUp = 0;
        else downOrUp = 1;
        double ans;
        if(!leftOrRight && !downOrUp){
            ans = sqrt((x1-w)*(x1-w)+(y1-h)*(y1-h));
        } else if(!leftOrRight && downOrUp){
            ans = sqrt((x1-w)*(x1-w)+(y1-(H-h))*(y1-(H-h)));
        } else if(leftOrRight && !downOrUp){
            ans = sqrt((x1-(W-w))*(x1-(W-w))+(y1-h)*(y1-h));
        } else {
            ans = sqrt((x1-(W-w))*(x1-(W-w))+(y1-(H-h))*(y1-(H-h)));
        }
        cout << ans << endl;
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
