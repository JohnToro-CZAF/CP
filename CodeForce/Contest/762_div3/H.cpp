#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pll;
typedef vector<pll> vlll;
typedef vector<vector<ll> > vvl;
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
const ll INF = 1e18+2;

int n, q, S;
vi P(maxn);
vi RP(maxn);
vi pre(maxn);
int pre_s(int index){
    int x = index;
    for(int i = 0; i < S; i++){
        x = P[x];
    }
    return pre[index] = x;
};
void solve(){
    cin >> n >> q;
    P = vi(n,0);
    RP = vi(n,0);
    pre = vi(n,0);
    S = int(0.45*sqrt(n))+1;
    forn(i, n){
        cin >> P[i];
        P[i]--;
        // cout << P[i] << " ";
    }
    forn(i, n){
        RP[P[i]] = i;
    }
    forn(i, n){
        pre_s(i);
    }
    while(q--){
        int type, x,y;
        cin >> type >> x >> y;
        if(type == 1){
            x--; y--;
            swap(RP[P[x]], RP[P[y]]);
            swap(P[x], P[y]);
            int cx = pre_s(x);
            int cy = pre_s(y);
            for(int i = 0; i <= S; i++){
                pre[x] = cx;
                pre[y] = cy;
                x = RP[x];
                y = RP[y];
                cx = RP[cx];
                cy = RP[cy];
            }
        } else {
            x--;
            while(y >= S){
                x = pre[x];
                y-=S;
            }
            while(y>0){
                x = P[x];
                y--;
            }
            cout << x+1 << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

