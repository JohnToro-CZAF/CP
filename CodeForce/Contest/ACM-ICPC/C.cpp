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
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    cin >> c1 >> c2;
    int area = a1 * a2 + b1 * b2 + c1 * c2;
    // cout << area << "\n";
    int side = sqrt(area);
    // cout << side << "\n";
    if ((side * side) != area){
        cout << "NO";
        return;
    }
    
    if (a1 < a2){
        int tmp = a1;
        a1 = a2;
        a2 = tmp;
    }
    if (b1 < b2){
        int tmp = b1;
        b1 = b2;
        b2 = tmp;
    }
    if (c1 < c2){
        int tmp = c1;
        c1 = c2;
        c2 = tmp;
    }
    // cout << a1 << " " << a2 << "\n";

    if ((a1 == side) && (b1 == side) && (c1 == side)){
        cout << "YES";
        return;
    }
    // cout << "NOT EQUAL\n";

    if (a1 == side){
        int common = side - a2;
        if (b1 == common && (c1 == common | c2 == common)){
            cout << "YES";
            return;
        }
        if (b2 == common && (c1 == common | c2 == common)){
            cout << "YES";
            return;
        }
        cout << "NO";
        return;
    }

    if (b1 == side){
        int common = side - b2;
        if (a1 == common && (c1 == common | c2 == common)){
            cout << "YES";
            return;
        }
        if (a2 == common && (c1 == common | c2 == common)){
            cout << "YES";
            return;
        }
        cout << "NO";
        return;
    }

    if (c1 == side){
        int common = side - c2;
        if (b1 == common && (a1 == common | a2 == common)){
            cout << "YES";
            return;
        }
        if (b2 == common && (a1 == common | a2 == common)){
            cout << "YES";
            return;
        }
        cout << "NO";
        return;
    }
    cout << "NO";
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

