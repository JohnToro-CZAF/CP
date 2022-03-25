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
    int n; cin >> n;
    vs s(n);
    set<string> se;
    map<string, vi> pos;
    forn(i, n){
        cin >> s[i];
        se.insert(s[i]);
        pos[s[i]].push_back(i);
    }
    forn(i, n){
        if(s[i].size() == 1){
            cout << "YES" << endl;
            return;
        }
        if(s[i].size() == 2){
            if(s[i][0] == s[i][1]){
                cout << "YES" << endl;
                return;
            }
        }
        if(s[i].size() == 3){
            if(s[i][0] == s[i][2]){
                cout << "YES" << endl;
                return;
            }
        }
    }   
    for(int i = 0; i <26; i++){
        for(int j = 0; j < 26; j++){
            string a = "";
            a += char(i+min_char);
            a += char(j+min_char);
            string b = "";
            b += char(j+min_char);
            b += char(i+min_char);
            if(se.find(a) != se.end() && se.find(b) != se.end()){
                cout << "YES" << endl;
                return;
            }
            for(int k = 0; k < 26; k++){
                char c = char(k+min_char);
                string a1 = a+c;
                string temp = a1;
                reverse(all(temp));
                string b1 = c+b;
                if(pos[a1].size() != 0 && pos[b].size() != 0){
                    if(pos[a1][0] < pos[b].back()){
                        cout << "YES" << endl;
                        return;
                    }
                } 
                if(pos[b1].size() != 0 && pos[a].size() != 0){
                    if(pos[b1].back() > pos[a][0]){
                        cout << "YES" << endl;
                        return;
                    }
                }
               if(pos[temp].size() != 0 && pos[a1].size() != 0){
                    cout << "YES" << endl;
                    return;
                }
            }
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

