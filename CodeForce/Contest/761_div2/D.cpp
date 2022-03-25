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
static T gcd (T a, T b) {long r, i;while(b!=0){r = a % b;a = b;b = r;}return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

int read(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << endl;
    cout.flush();
    int k;
    cin >> k;
    return k;
}

void solve(){
    int n;
    cin >> n;
    int index;
    int b[n];
    mem(b, 0);
    for(int i = 1; i <= n-2; i++){
        int res = read(i, i+1, i+2);
        b[i] = res;
    }
    for(int i = 1; i <= n-3; i++){
        if(b[i] != b[i+1]){
            index = i;
            break;
        }
    }
    int cnt = 0;
    vi ans;
    vi te;
    for(int i = 1; i <= n; i++){
        if(i!=index && i!= index+3){
            if(read(i, index, index+3) == 0){ans.push_back(i); cnt++;}
            else te.push_back(i);
        }
    }
    if(read(index, te[0], ans[0]) == 0){ans.push_back(index); cnt++;}
    else{ans.push_back(index+3); cnt++;}

    cout << "! " << cnt << " ";
    for(auto x : ans){
        cout << x << " ";
    }
    // cout << index << " " << index+3 << endl;
    cout.flush();
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

