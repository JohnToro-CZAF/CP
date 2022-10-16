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
    ll n,i,j,k,l;
    ll maxprime=3000;
    vector<ll> prime;
    vector<bool> isprime(3000);
    for(i=2;i<maxprime;i++){
        isprime[i]=true;
    }
    for(i=2;i<maxprime;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(j=2;(ll)(j*i)<maxprime;j++){
                isprime[i*j]=false;
            }
        }
    }
    cin >> n;
    vector<ll> a(n+1), x(n+1);
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    x[0]=0;
    for(i=1;i<=n;i++){
        if(a[i]!=0){
            x[i]=i;
        }
        else{
            x[i]=x[i-1];
        }
    }
    for(i=0;i<=n;i++){
        dp[0][i]=1;
    }
    
    for(i=1;i<=n;i++){
        for(j=0;j<n+1;j++){
            dp[i][j]=0;
            for(k=i-1;k>=x[i];k--){
                dp[i][j]=(dp[i][j]+dp[k][j])%prime[j];
            }
            bool able=true;
            if(x[i]==0){
                able=false;
            }
            else{
                if(i+1-x[i]>a[x[i]]||a[x[i]]>i){
                    able=false;
                }
                else{
                    for(l=i;l>=i+1-a[x[i]];l--){
                        if(a[l]>0&&a[l]!=a[x[i]]){
                            able=false;
                        }
                    }
                }
            }
            if(able){
                dp[i][j]=(dp[i][j]+dp[i-a[x[i]]][j])%prime[j];
            }
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    
    bool able=true;
    for(i=0;i<n+1;i++){
        if(dp[n][i]!=1){
            able=false;
        }
    }
    if(able){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    c=1;
 //   cin >> c;
    while(c--){
        solve();
    }
}