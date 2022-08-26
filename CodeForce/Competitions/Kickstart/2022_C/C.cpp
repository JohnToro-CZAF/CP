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
string LongestPalindromicPrefix(string str)
{
 
    // Create temporary string
    string temp = str + '?';
 
    // Reverse the string str
    reverse(str.begin(), str.end());
 
    // Append string str to temp
    temp += str;
 
    // Find the length of string temp
    int n = temp.length();
 
    // lps[] array for string temp
    int lps[n];
 
    // Initialise every value with zero
    fill(lps, lps + n, 0);
 
    // Iterate the string temp
    for (int i = 1; i < n; i++) {
 
        // Length of longest prefix
        // till less than i
        int len = lps[i - 1];
 
        // Calculate length for i+1
        while (len > 0
               && temp[len] != temp[i]) {
            len = lps[len - 1];
        }
 
        // If character at current index
        // len are same then increment
        // length by 1
        if (temp[i] == temp[len]) {
            len++;
        }
 
        // Update the length at current
        // index to len
        lps[i] = len;
    }
 
    // Print the palindromic string of
    // max_len
    return temp.substr(0, lps[n - 1]);
}

void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

bool isPalindrome(string S)
{
    // Stores the reverse of the
    // string S
    string P = S;
 
    // Reverse the string P
    reverse(P.begin(), P.end());
 
    // If S is equal to P
    if (S == P) {
        // Return "Yes"
        return true;
    }
    // Otherwise
    else {
        // return "No"
        return false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    for (auto case_num = 1; case_num <= T; ++ case_num) {
        int n; cin >> n;
        string p;
        cin >> p;
        string t = p.substr(1, n-1);
        reverseStr(t);
        string ans = LongestPalindromicPrefix(t);
        // cout << ans << endl;
        int m = ans.length();
        string u = p.substr(0, n-m);
        reverseStr(u);   
        if(m == 1){
            cout << "Case #" << case_num << ": " << p;
            cout << endl;
            continue;
        }
        cout << "Case #" << case_num << ": " << u;
        cout << endl;
    }
    return 0;
}

