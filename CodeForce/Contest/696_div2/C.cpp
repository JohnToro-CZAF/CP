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
    int n;
    cin >> n;
    int a[2*n];
    multiset<int, greater<int> > s;
    forn(j, 2*n){
        cin >> a[j];
    }
    sort(a, a+2*n);
    int x;
    for(int i = 0; i < 2*n-1; i++){
        s.clear();
        forn(j, 2*n){
            s.insert(a[j]);
        }
        bool ok = false;
        vector<pii> ans;
        int cnt = 2*n;
        int chosen = i;
        x = a[i]+a[2*n-1];
        ans.push_back(make_pair(a[i], a[2*n-1]));
        auto it1 = s.lower_bound(a[i]);
        s.erase(it1);
        s.erase(s.begin());
        int t = a[2*n-1];
        cnt-=2;
        if(cnt == 0){
            cout << "YES" << endl;
            cout << x << endl;
            for(auto p : ans){
                cout << p.first << " " << p.second << endl;
            }
            return;
        }
        while(true){
            // for(auto u : s){
            //     cout << u << " ";
            // }
            // cout << endl;
            int last = *s.begin();
            s.erase(s.begin());
            auto it1 = s.lower_bound(t-last);
            if(it1 != s.end() && *it1 == t-last){
                s.erase(it1);
                ans.push_back(make_pair(t-last, last));
                cnt -= 2;
                t = last;
            } else {
                break;
            }
            if(cnt == 0){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << "YES" << endl;
            cout << x << endl;
            for(auto p : ans){
                cout << p.first << " " << p.second << endl;
            }
            return;
        }
    }
    cout << "NO" << endl;
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

