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
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
// using namespace __gnu_pbds;
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
    int n, d; cin >> n >> d;
    vi a(n);
    bool run = false;
    forn(i, n){
        cin >> a[i];
        if(a[i] == 1){
            run = true;
        }
    }
    bool looped[n+1];
    vvi cycle;
    mem(looped, false);
    if(!run){
        cout << 0 << endl; 
        return;
    } else {
        if(d == n){
            cout << -1 << endl;
            return;
        }
    }
    // cout << "start" << endl;
    // int count = 0;
    for(int i = 0; i < n; i++){
        if(!looped[i]){
            vi temp;
            temp.push_back(i);
            int s = i;
            int it = i;
            looped[i] = true;
            while((it+d)%n != s){
                // cout << "cac" << endl;
                looped[it] = true;
                temp.push_back((it+d)%n);
                it += d;
                it %= n;
            }
            cycle.push_back(temp);
            // count++;
        }
    }
    int mx = 0;
    for(auto v : cycle){
        // for(auto u : v){
        //     cout << u << " ";
        // }
        // cout << endl;
        // for(auto u : v){
        //     cout << a[u] << " ";
        // }
        // cout << endl;
        int s = int(v.size());
        vi pos0;
        for(int i = 0; i < s; i++){
            if(a[v[i]] == 0){
                pos0.push_back(i);
            }
        }
        if(pos0.size() == 0){
            cout << -1 << endl;
            return;
        }
        int last = -(s-pos0[int(pos0.size())-1]);
        // cout << last << endl;
        for(int i = 0; i < s; i++){
            if(a[v[i]] == 0){
                last = i;
            } else {
                mx = max(mx, i-last);
            }
        }
    }
    cout << mx << endl;
    // a.order_of_key(element) : finding the enumber of elements which strictly less than element in the container
    // a.insert
    // a.find_by_order(k) : returning pointer point toward to k-th element in the container

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

