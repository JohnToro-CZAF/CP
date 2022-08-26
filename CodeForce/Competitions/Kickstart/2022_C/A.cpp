#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
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
const char min_char = 'a';

 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    for (auto case_num = 1; case_num <= T; ++ case_num) {
        string s;
        int n;
        cin >> n;
        cin >> s;
        set<char> se;
        string ans = s;
        int sep[4];
        forn(i, 4){
            sep[i] = 0;
        }
        se.insert('@'); se.insert('#'); se.insert('&'); se.insert('*');
        forn(i, n){
            if(se.find(s[i]) != se.end()){
                sep[0] = 1;
            }
                if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
                    sep[1] = 1;
                }
            if(isupper(s[i]) && s[i]-'A' >= 0 && s[i]-'A' <= 25){
                sep[2] = 1;
            }
            if(s[i]-'a' >= 0 && s[i]-'a' <= 25){
                sep[3] = 1;
            }
        }
        forn(i, 4){
            // cout << sep[i] << " ";
        }
        // cout << endl;
        int seu = 0;
        forn(i, 4){
            seu += sep[i];
        }
            if(!sep[0]){
                ans = ans+'*';
            }
            if(!sep[1]){
                ans = ans+'1';
            } 
            if(!sep[2]){
                ans = ans+'A';
            }
            if(!sep[3]){
                ans = ans + 'a';
            }
        // cout << ans << endl;
        int t = 7-int(ans.size());
        if(int(ans.size()) < 7){
            for(int j = 0; j < t; j++){
                // cout << "cac" << endl;
                ans = ans+'1';
            }
        }
        cout << "Case #" << case_num << ": " << ans << endl;
    }
    return 0;
}

