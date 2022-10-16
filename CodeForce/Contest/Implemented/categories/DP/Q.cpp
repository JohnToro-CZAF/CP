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

template<typename T>
inline T mul(T x, T y){return (x%MOD)*(y%MOD)%MOD;}

template<typename T>
inline T add(T x, T y) {x%=MOD;y%=MOD;x += y;if(x >= MOD) x-=MOD;return x;}

class SegmentTree{
private:
  std::vector<ll> aint;
  int n;
 
  ll join(ll x, ll y) {
    return max(x, y);
  }
  
  void _update(int node, int from, int to, int x, ll val) {
    if(from < to) {
      int mid = (from + to) / 2;
      if(x <= mid)
        _update(node * 2, from, mid, x, val);
      else
        _update(node * 2 + 1, mid + 1, to, x, val);
      aint[node] = join(aint[node * 2], aint[node * 2 + 1]);
    } else
      aint[node] = val;
  }
 
  ll _query(int node, int from, int to, int x, int y) {
    if(from == x && to == y) {
      return aint[node];
    } else {
      int mid = (from + to) / 2;
      if(x <= mid && y <= mid)
        return _query(node * 2, from, mid, x, y);
      else if(mid + 1 <= x && mid + 1 <= y)
        return _query(node * 2 + 1, mid + 1, to, x, y);
      else
        return join(_query(node * 2, from, mid, x, mid),
                    _query(node * 2 + 1, mid + 1, to, mid + 1, y));
    }
  }
  
  void _print(int node, int from, int to) {
    if(from < to) {
      int mid = (from + to) / 2;
      _print(node * 2, from, mid);
      _print(node * 2 + 1, mid + 1, to);
    } else
      std::cout << aint[node] << " ";
  }
 
public:
  SegmentTree(int n_) {
    n = n_;
    aint.resize(1 + 4 * n);
  }
  
  void update(int x, ll val) {
    _update(1, 1, n, x, val);
  }
  
  ll query(int x, int y) {
    return _query(1, 1, n, x, y);
  }
 
  void print() {
    std::cout << "Print array\n";
    _print(1, 1, n);
    std::cout << '\n';
  }
};
 
/*
One easy way to normalize an array is to first create a copy of it. 
Let 'v' be the array to be normalized and 'aux' its duplicate.
Then, sort the copy and erase the dublicates.
Thus, 'aux' contains all the distinct elements in 'v'.
Now, we simply have to find for each element in 'v' its position in 'aux'. 
This can be easily done using binary search or the STL-provided lower_bound function.
*/
 
void normalize(vector<ll> &v) {
  std::vector<ll> aux = v;
  std::sort(aux.begin(), aux.end());
  aux.erase(std::unique(aux.begin(), aux.end()), aux.end());
  for(int i = 0; i < v.size(); i++)
    v[i] = std::lower_bound(aux.begin(), aux.end(), v[i]) - aux.begin() + 1;
}
 
void solve(){
    int n; cin >> n;
    vector<ll> h(n), a(n);
    forn(i, n){
        cin >> h[i];
    }
    forn(i, n){
        cin >> a[i];
    }
    normalize(h);
    SegmentTree segTree(n);
    for(int i = 0; i < n; i++) {
        ll result = 0;
        if(1 < h[i])
          result = segTree.query(1, h[i] - 1);
        else
          result = 0;
        segTree.update(h[i], result + a[i]);
    }
    // cout << segTree.query(0, 1) << endl;
    ll ans = segTree.query(1, n);
    cout << ans << endl;
}

int main(){
    int c = 1;
    while(c--){
        solve();
    }
    return 0;
}


