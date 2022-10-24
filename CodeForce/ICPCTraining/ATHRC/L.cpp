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

struct Vector{
    long double x,y;
    Vector(){}
    Vector(long double x, long double y) : x(x), y(y){}
    Vector operator+(const Vector& T) const {
        return Vector(x + T.x, y + T.y);
    }
    Vector operator-(const Vector& T) const {
        return Vector(x - T.x, y - T.y);
    }
    long double len() const {
        return sqrt(x*x + y*y);
    }
    double dot(const Vector& T){
        return x*T.x + y*T.y;
    }
    long double cross(const Vector& T){
        return x*T.y - y*T.x;
    }

};

typedef Vector Point;

bool cmp(const Point& A, const Point& B){
    return A.x < B.x;
}

bool cmp1(const Point& A, const Point& B){
    return A.y < B.y;
}

void solve(){
    int n; cin >> n;
    vector<Point> points;
    forn(i, n){
        long double x, y; cin >> x >> y;
        points.push_back(Point(x, y));
    }
    sort(all(points), cmp); 
    Point A = points[0]; Point B = points[n-1];
    long double ans = 0.0;
    vector<Point> temp(3);
    for(int i = 1; i < n-1; i++){
        for(int j = i+1; j < n-1; j++){
            temp[0] = points[i]; temp[1] = points[j]; temp[2] = B;
            vector<int> ids = {0, 1, 2};
            int cnt = 0;
            sort(all(temp), cmp1);
            do {
                if(cnt == 3){
                    break;
                }
                cnt++;
                long double sum = 0;
                for(int k = 0; k < 2; k++){
                    sum += (temp[ids[k]] - A).cross(temp[ids[(k+1)]] - A);
                }
                // sum *= 0.5;
                ans = max(ans, sum); 
            } while (next_permutation(all(ids)));
        }
    }
    cout << ((maxs & 1ll) ? to_string(maxs / 2ll) + ".5\n" : to_string(maxs / 2ll) + "\n");
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