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
    //phuoc
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    forn(i, n){
        string s;
        cin >> s;
        forn(j, m){
            if (s[j] == 'L'){
                grid[i][j] = 1;
            }
            else if (s[j] == 'W'){
                grid[i][j] = 0;
            }
            else{
                grid[i][j] = 2;
            }
        }
    }

    vector<pii> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int color = 0;
    forn(i, n){
        forn(j, m){
            if (grid[i][j] != 1) continue;
            if (vis[i][j]) continue;
            color++;
            queue<pii> st;
            st.push({i, j});
            while (!st.empty()){
                pii curr = st.front();
                st.pop();
                int x = curr.first, y = curr.second;
                vis[x][y] = 1;
                for (pii dir: direction){
                    int xx = x + dir.first, yy = y + dir.second;
                    if (0 <= xx && xx < n && 0 <= yy && yy < m){
                        if (grid[xx][yy] != 0){
                            if (vis[xx][yy]) continue;
                            st.push({xx, yy});
                        }
                    }
                }
            }
        }
    }

    cout << color << "\n";
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

