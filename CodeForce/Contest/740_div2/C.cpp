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
    vi temp;
    vii next;
    int first = 0;
    forn(i, n){
        int k;
        temp.push_back(first);
        cin >> k;
        first += k;
        int m = 0;
        forn(i, k){
            int x;
            cin >> x;
            x -= i;
            m = max(x, m);
            // cout << m << " ";
        }
        // cout << "\n";
        // next.push_back(m);
        next.push_back(make_pair(m, k));
    }
    sort(all(next));
    int t = int(temp.size());
    // cout << "size" << t << endl;
    int keep = 0;
    int m = 0;
    for(int i = 0; i < t; i++){
        m = max(m, next[i].first-keep);
        keep += next[i].second;
    }
    // int ans = next.back().first;
    // int res = next.back().second;
    cout << max(1, m+1)<< endl;
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

