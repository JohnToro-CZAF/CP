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
    int n; cin >> n;
    vi a(n);
    vi pos;
    forn(i, n){
        cin >> a[i];
    }
    pos.push_back(-1);
    forn(i, n){
        if(a[i] == 0){
            pos.push_back(i);
        }
    }
    pos.push_back(n);
    int m = 0;
    pii best = make_pair(0, n);
    // for(auto u : pos){
    //     cout << u << " ";
    // }
    // cout << "case" << endl;
    for(int i = 0; i+1 < pos.size(); i++){
        int cnt1 = 0, cnt11 = 0;
        int cnt2 = 0, cnt22 = 0;
        int last = -1;
        int first = -1;
        for(int j = pos[i]+1; j < pos[i+1]; j++){
            if(a[j] < 0 && first == -1){
                first = j;
            }
            if(a[j] < 0){
                last = j;
            }
            if(a[j] == -2){
                cnt22++;
            } else if(a[j] == 2){
                cnt2++;
            } else if(a[j] == 1){
                cnt1++;
            } else {
                cnt11++;
            }
        }  
        if((cnt11 + cnt22)%2 == 0){
            if(cnt22+cnt2 > m){
                best = make_pair(pos[i]+1, n-pos[i+1]);
                m = cnt22+cnt2;
            }
        } else {
            int cnt = 0;
            for(int j = first+1; j < pos[i+1]; j++){
                if(a[j] == 2 || a[j] == -2){
                    cnt++;
                }
            }
            if(cnt > m){
                m = cnt;
                best = make_pair(first+1, n-pos[i+1]);
            }
            cnt = 0;
            for(int j = pos[i]+1; j < last; j++){
                if(a[j] == 2 || a[j] == -2){
                    cnt++;
                }              
            }
            if(cnt > m){
                m = cnt;
                best = make_pair(pos[i]+1, n-last);
            }      
        }
        // cout << best.first << " " << best.second << endl;
    }
    cout << best.first << " " << best.second << endl;
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

