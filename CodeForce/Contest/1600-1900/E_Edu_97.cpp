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
    double c1, t1, p, v;
    cin >> c1 >> t1 >> p >> v;
    float res = 0;
    for(int l = 1; l <= 20; l++){
        float ans = 0;
        for(int i = 0; i < (1ll<<(l-1)); i++){
            if(l == 1){
                ans += p;
                break;
            } else {
                float pro = 1.0f;
                int run = 0;
                float c = c1, m = t1, t = p;
                for(int j = l-2; j >= 0; j--){
                    if((i>>j)&1){
                        if(m < 0.00000018){break;}
                        if(m <= v){
                            pro*=m;
                            if(c < 0.0000018){
                                t += m;
                            } else {
                                c += m/2;
                                t += m/2;
                            }
                            m = 0.0f;
                        } else {
                            pro*=m;
                            if(c < 0.0000018){
                                t += v;
                            } else {
                                c += v/2;
                                t += v/2;
                            }
                            m -= v;
                        }
                    } else {
                        if(c < 0.0000018){
                            break;
                        }
                        if(c <= v){
                            pro *= c;
                            if(m < 0.0000018){
                                t += c;
                            } else {
                                m += c/2;
                                t += c/2;
                            }
                            c = 0.0f;
                        } else {
                            pro*=c;
                            c -= v;
                           if(m < 0.0000018){
                                t += v;
                            } else {
                                m += v/2;
                                t += v/2;
                            }
                        }
                    }
                    if(j == 0){
                        run = 1;
                    }
                }
                if(run == 1){
                    if(t <= 1){
                        pro*=t;
                    }
                    ans += pro;
                }
            }
        }
        ans *= l;
        res += ans;
    }
    std::cout << std::fixed << std::setprecision(12) << res << endl;;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c; cin >> c;
    while(c--){
        solve();
    }
}

