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
void solve(){
    int n, k;
    cin >> n >> k;
    vi digit;
    int cp = n;
    while(cp!=0){
        digit.push_back(cp%10);
        cp/=10;
    }
    reverse(all(digit));
    int mi = INF, s = digit.size(), f = digit[0];
    if(k >= 1){
        int res = 0, it = 0;
        while(it < s){
            res += power(10, it)*f;
            it++;
        }
        if(res >= n){
            mi = min(res, mi);
        }
        it = 0; res = 0; 
        while(it < s){
            res += power(10, it)*min(9, f+1);
            it++;
        }
        if(res >= n){
            mi = min(res, mi);
        }
    }
    if(k == 2){
        int res = 0;
        res += power(10, s-1)*min(f+1, 9);
        if(res >= n){
            mi = min(res, mi);
        }
    }
    if(k == 2){
        int f = digit[0];
        for(int j = 0; j < 10; j++){
            vi ans = digit;
            for(int i = 0; i < s; i++){
                if(ans[i] != f){
                    ans[i] = j;
                }
            }
            int res = 0, it = 0;
            reverse(all(ans));
            while(it < s){
                res += power(10, it)*ans[it];
                it++;
            }
            if(res >= n){
                mi = min(res, mi);
            }
        }
    }
    // cout << res << endl;
    if(k == 2){
        int it = 0;
        while(it < s && digit[it] == f){
            // cout << "loz" << endl;
            it++;
        }
        if(it < s){
            int res = 0;
            vi ans = digit;
            int se = digit[it];
            // cout << se << endl;
            int run = 0;
            for(int i = it+1; i < s; i++){
                if(digit[i] > max(se, f)){
                    run = 1;
                    break;
                } else {
                    if(digit[i] <= min(se, f)){
                        ans[i] = min(se, f);
                    } else {
                        ans[i] = max(se, f);
                    }
                }
            }
            if(run == 1){
                vi ori = digit;
                ori[it]++;
                if(ori[it] < 10){
                    for(int i = it+1; i < s; i++){
                        ori[i] = min(ori[it], f);
                    }
                    reverse(all(ans));
                    for(int i = s - 1; i >= 0; i--){
                        res += power(10, s-i-1)*ori[i];
                    }
                    // cout << res << endl;
                    if(res >= n){
                        mi = min(res, mi);
                    }                    
                }
            } else {
                reverse(all(ans));
                for(int i = s - 1; i >= 0; i--){
                    res += power(10, s-i-1)*ans[i];
                }
                if(res >= n){
                    mi = min(res, mi);
                }
            }
        }
    }
    cout << mi << endl;
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

