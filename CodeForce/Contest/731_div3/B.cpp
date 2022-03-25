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
    string s;
    cin >> s;
    bool f = false;
    int index;
    for(int i = 0; i < int(s.size()); i++){
        if(s[i] == 'a'){
            f = true;
            index = i;
        }
    }
    int n = s.size();
    int len = s.size();
    len--;
    if(f){
        int l = index;
        int r = l;
        while(len--){
            char next = char('a'+int(s.size())-len-1);
            // cout << next << endl;
            bool ex = false;
            int index;
            for(int i = 0; i < n; i++){
                if(next == s[i]){
                    index = i;
                    ex = true;
                }
            }
            if(ex){
                if(index == l-1) l = l-1;
                else if(index == r+1) r = r+1;
                else{
                    cout << "NO" << endl;
                    return;
                }
            } else {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    // gen('a', 1);
    cin >> c;
    while(c--){
        solve();
    }
}

