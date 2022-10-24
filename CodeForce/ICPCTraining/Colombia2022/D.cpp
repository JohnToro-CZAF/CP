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
    string s;
    cin >> s;
    s.push_back('a');
    vi coefs(400, 0);
    int sign = 1;
    int i = 0;
    while (true){
        if (i == 0 && s[0] == '-'){
            // cout << "true" << "\n";
            i++;
            sign = -1;
        }

        int coef = 0;

        if (s[i] == 'x'){
            // if(i >= 1 && s[i-1]-'0' >= 0 && s[i-1] - '0' <= 9){

            // }
            coef = 1; 
        }

        // cout << "sign " << sign << "\n";

        while ((s[i] - '0') >= 0 && (s[i] - '0') <= 9){
            coef = coef * 10 + (s[i] - '0');
            i++;
        }

        // cout << "coef " << coef << "\n";


        if (s[i] == 'x'){
            i++;
            if (s[i] == '^'){
                i++;
                int power = 0;
                int power_sign = 1;
                if (s[i] == '-'){
                    power_sign = -1;
                    i++;
                }
                while ((s[i] - '0') >= 0 && (s[i] - '0') <= 9){
                    power = power * 10 + (s[i] - '0');
                    i++;
                }

                coefs[power_sign * power + 200] += sign * coef;
                if (s[i] == 'a') break;
                if (s[i] == '+') sign = 1;
                if (s[i] == '-') sign = -1;
                i++;

            }
            else{
                coefs[201] += sign * coef;
                if (s[i] == 'a') break;
                if (s[i] == '+') sign = 1;
                if (s[i] == '-') sign = -1;
                i++;
            }
        }

        else{
            coefs[200] += sign * coef;
            // cout << coefs[200] << "\n";
            if (s[i] == 'a') break;
            if (s[i] == '+') sign = 1;
            if (s[i] == '-') sign = -1;
            i++;
        }
    }

    vi new_coefs(400, 0);
    forn(i, 400){
        if (i == 0) continue;
        new_coefs[i - 1] = coefs[i] * (i - 200);
    }

    // cout << new_coefs[200] << "\n";

    bool flag = false;
    forn(i, 400){
        if (new_coefs[i] == 0) continue;
        if (new_coefs[i] >= 0){
            if (flag) cout << '+';
            cout << new_coefs[i];
        }
        else{
            cout << new_coefs[i];
        }
        flag = true;
        if (i == 200){
            continue;
        }
        cout << "x";
        if (i == 201){
            continue;
        }
        cout << "^" << i - 200;
    }

    if (!flag) cout << 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    // cin >> c;
    c = 1;
    while(c--){
        solve();
    }
}

