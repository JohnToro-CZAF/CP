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
int m, n, s;

void printa(vvi& a){
    cout << "test" << endl;
    for(auto v : a){
        for(auto i : v){
            cout << i << " ";
        }
        cout << endl;
    }
}

void solve(){
    cin >> m >> n >> s;
    vvi table(m, vi());
    forn(i, m){
        forn(j, n){
            int x; cin >> x;
            table[i].push_back(x);
        }
    }
    vvi finaltab = table;
    forn(i, s){
        int x; cin >> x; x--;
        vector<pii> temp;
        forn(j, m){
            temp.push_back({finaltab[j][x], j});
        }
        sort(all(temp));
        vvi temptab;
        forn(j, m){
            temptab.push_back(finaltab[temp[j].second]);
        }
        // printa(temptab);
        finaltab = temptab;
    }
    // cout << "cac" << endl;
    vi nxt;
    if(finaltab == table){
        cout << 0 << endl;
        return;
    }
    forn(i, n){
        nxt.push_back(i);
    }
    vi best;
    int ans = 9;
    do {    
        vi tempbst;
        vvi temptab = table;
        int cnt = 0;
        for(auto idx : nxt){
            // cout << idx;
            tempbst.push_back(idx);
            vector<pii> temp;
            forn(i, m){
                temp.push_back({temptab[i][idx], i});
            }
            sort(all(temp));
            vvi cptab;
            forn(i, m){
                cptab.push_back(temptab[temp[i].second]);
            }
            temptab = cptab;            
            cnt++;
            // printa(temptab);
            if(finaltab == temptab){
                if(cnt < ans){
                    best = tempbst;
                    ans = cnt;
                }
                break;
            }
        }
        // cout << endl;
    } while(next_permutation(all(nxt)));
    cout << ans << endl;

    for(int i : best){
        cout << i+1 << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c = 1;
    // cin >> c;
    while(c--){
        solve();
    }
}
