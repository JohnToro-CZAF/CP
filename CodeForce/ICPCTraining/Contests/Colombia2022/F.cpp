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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
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
typedef pair<int, char> node; 
typedef tree<node, null_type, less<node>,
            rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ordered_set a;
vector<char> v;
void solve(){
    int n, q,i,j, type, vitri,beg;
    char b, x; cin >> n >> q;
    int hang[n+1],cot[n+1],temp[n+1];
    // pii pa,pa_a;
    ordered_set::iterator pa, pa_a;
    int r,c;
    string s[n+1];
    int ans = 0;
    for(i=0;i<n;i++){
        cot[i]=0;
        hang[i]=0;
    }
    for(i=1;i<=n;i++){
        cin >> s[i];
    }
    for(i=n;i>=1;i--){
        for(j=n-1;j>=0;j--){
            v.push_back(s[i][j]);
            hang[n-i]+=(s[i][j]-'0');
            cot[n-1-j]+=(s[i][j]-'0');
        }
    }
    beg=0;
    for(j=1;j<=q;j++){
        cin >> type;
        if(type==1){
            cin >> r >> c >> b;
            r=n-r;
            c=n-c;
            hang[r]+=(b-v[r*n+c+beg]);
            cot[c]+=(b-v[r*n+c+beg]);
            v[r*n+c+beg]=b;
        }
        else{
            cin >> b;
            for(i=0;i<n;i++){
                temp[i]=cot[i];
            }
            for(i=0;i<n-1;i++){
                cot[i]=temp[i+1];
            }
            cot[n-1]=temp[0]+(b-v[beg]);
            for(i=0;i<n;i++){
                x=v[beg+i*n];
                hang[i]-=(x-'0');
            }
            v.push_back(b);
            beg++;
            for(i=0;i<n;i++){
                x=v[beg+i*n+n-1];
                hang[i]+=(x-'0');
            }
        }
        ans=0;
        for(i=0;i<n;i++){
            if(hang[i]==n){
                ans++;
            }
            if(cot[i]==n){
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}