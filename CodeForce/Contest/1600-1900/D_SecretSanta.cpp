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

const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';


void solve(){
    int n;
    cin >> n;
    vvi cycle;
    vi a(n);
    vi b(n, -1);
    vi c(n);
    forn(i, n){
        cin >> a[i]; a[i]--;
        c[i] = a[i];
    }
    vi used(n, 0);
    forn(i, n){
        if(!used[a[i]]){
            used[a[i]] = 1;
        } else { 
            a[i] = -1;
        }
    }
    int cnt = 0;
    forn(i, n){
        if(a[i] != -1){
            b[a[i]] = i;
            cnt++;
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] == -1){
            vi temp;
            int old = i;
            int j = b[i];
            if(j == -1){
                cycle.push_back({i});
                continue;
            }
            temp.push_back(i);
            while(j != -1 && j != old){
                temp.push_back(j);
                j = b[j];
            }
            reverse(all(temp));
            if(j == -1){
                cycle.push_back(temp);
            }
        }
    }
    if(cycle.size() == 1){
        if(cycle[0].size() > 1){
            a[cycle[0].back()] = cycle[0][0];
        } else {
            int s = cycle[0][0];
            int nxt = c[s];
            forn(i, n){
                if(a[i] == nxt){
                    a[i] = s;
                    break;
                }
            }
            a[s] = nxt;
        }
    } else if(cycle.size() > 1){
        int first = cycle[0][0];
        for(int i = 0; i < int(cycle.size())-1; i++){
            a[cycle[i].back()] = cycle[i+1][0];
        }
        a[cycle[int(cycle.size())-1].back()] = first;
    }
    cout << cnt << endl;
    forn(i, n){
        cout << a[i]+1 << " ";
    }
    cout << endl;
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

