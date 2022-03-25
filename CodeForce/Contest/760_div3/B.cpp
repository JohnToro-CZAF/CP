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
    vector<char> ans;
    vector<pair<char, char> > temp(n-2);
    bool flag = true;
    forn(i, n-2){
        char x, y;
        cin >> x >> y;
        temp[i] = make_pair(x, y);
    }
    forn(i, n-3){
        if(temp[i].second != temp[i+1].first){
            flag = false;
        }
    }
    if(!flag){
        forn(i, n-2){
            if(i <= n-4 && temp[i].second != temp[i+1].first){
                ans.push_back(temp[i].first);
                ans.push_back(temp[i].second);
            } else {
                ans.push_back(temp[i].first);
            }       
        } 
        ans.push_back(temp[n-3].second);
        // cout << "du" << endl;
    } else {
        forn(i, n-2){
            ans.push_back(temp[i].first);
        } 
        ans.push_back(temp[n-3].second);
        ans.push_back('b');
    }
    for(auto x : ans){
        cout << x;
    }
    cout << "\n";
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

