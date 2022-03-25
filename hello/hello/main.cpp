//
//  main.cpp
//  hello
//
//  Created by johntoro on 20/03/2022.
//
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

ll dp[12][2][2][109][109];
int check[12][2][2][109][109];
int cur = 0;

ll count(int index, int larger, int smaller, int left,
        int mod, int sum, string L, string R, int leading) {
    if (index == L.size()) {
        if (left == 0 && mod == 0) {
            return 1;
        }
        return 0;
    }
    if((L.size() - index) * 9 < left){
        return 0;
    }
    if (check[index][larger][smaller][left][mod] == 1) {
        return dp[index][larger][smaller][left][mod];
    }
    check[index][larger][smaller][left][mod] = 1;
    int x = L[index] - '0';
    int y = R[index] - '0';
    ll result = 0;
    for (int i = 0; i < 10 && i <= left; i++) {

        if (x > i && larger == 0) {
            continue;
        }
        if (y < i && smaller == 0) {
            continue;
        }
        int nxtLarger = larger;
        int nxtSmaller = smaller;
        if (x < i) {
            nxtLarger = 1;
        }
        if (y > i) {
            nxtSmaller = 1;
        }
        if(leading == 1 && i == 0){
            result += count(index + 1, nxtLarger, nxtSmaller, left - i, 1,
            sum, L, R, 1);
        } else if (leading == 1 && i!=0){
            result += count(index + 1, nxtLarger, nxtSmaller, left - i, i%sum,
            sum, L, R, 0);
        } else {
            int nxtMod = (mod*i)%sum;
            result += count(index + 1, nxtLarger, nxtSmaller, left - i, nxtMod,
            sum, L, R, 0);
        }
    }
    return dp[index][larger][smaller][left][mod] = result;
}
void solve(int ca){
    cur = 0;
    ll l ,r;
//    cout << "Enter the number here : " << endl;
    cin >> l >> r;
    mem(dp, 0);
    forn(i, 12){
        forn(j, 2){
            forn(k, 2){
                forn(t, 109){
                    forn(u, 109){
                        dp[i][j][k][t][u] = 0;
                    }
                }
            }
        }
    }
    forn(i, 12){
        forn(j, 2){
            forn(k, 2){
                forn(t, 109){
                    forn(u, 109){
                        check[i][j][k][t][u] = 0;
                    }
                }
            }
        }
    }
    string L = to_string(l);
    string R = to_string(r);
    while(L.size() < R.size()){
        L = "0"+L;
    }
    // cout << L << " " << R << endl;
    ll cnt = 0;
    for(int i = 1; i <= 108; i++){
        cur += 1;
        cnt += count(0, 0, 0, i, 1, i, L, R, 1);
    }
    cout << "Case #" << ca << ": " << cnt << endl;
}

int main(int argc, const char * argv[]){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    int ca = 1;
    while(c--){
        solve(ca++);
    }
}
