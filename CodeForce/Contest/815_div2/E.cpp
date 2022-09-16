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

const int maxn = 1e5*31 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';

vector<vector<ll> > nxt;
vector<ll> num;

void solve(){
    int n, k;
    cin >> n >> k;
    nxt = vector<vector<ll> >(1, vector<ll>(2, 0));
    num = vector<ll>(1, 0);
    vi a(n+1);
    a[0] = 0;
    forn(i, n) cin >> a[i+1];
    int N = 0;
    int x = 0;
    ll mx = 0;
    // 5 0 5 0 5
    // 2 0 2 0 2 
    for(int j = 0; j <= n; j++){
        x ^= a[j];
        int node = 0;
        ll candidate = 0;
        for(int i = 30; i >= 0; i--){
            int p = ((1<<i)&k) ? 1 : 0;
            int q = ((1<<i)&x) ? 1 : 0;
            if(p == 1 && q == 0){
                if(nxt[node][0]){
                    candidate += num[nxt[node][0]];
                } 
                if(nxt[node][1]){
                    node = nxt[node][1];
                } else {
                    break;
                }
            } else if(p == 1 && q == 1){
                if(nxt[node][1]){
                    candidate += num[nxt[node][1]];
                }
                if(nxt[node][0]){
                    node = nxt[node][0];
                } else {
                    break;
                }
            } else if(p == 0 && q == 0){
                if(nxt[node][0]){
                    node = nxt[node][0];
                } else {
                    break;
                }
            } else if(p == 0 && q == 1) {
                if(nxt[node][1]){
                    node = nxt[node][1];
                } else {
                    break;
                }
            }
        }
        node = 0;
        for(int i = 30; i >= 0; i--){
            int bit = ((1<<i)&x) ? 1 : 0;
            if(!nxt[node][bit]){
                nxt[node][bit] = ++N;
                nxt.push_back(vector<ll>(2));
                num.push_back(0);
            }
            node = nxt[node][bit]; 
            num[node]++;
        }
        mx += candidate;
    }
    cout << mx << endl;
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

