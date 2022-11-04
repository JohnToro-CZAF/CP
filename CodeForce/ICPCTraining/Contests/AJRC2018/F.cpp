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
vi dx = {-2, -2, -2, 2, -4, 4};
vi dy = {-6, 6, 6, -6, 0, 0};

vi checkx = {-1, 1, -1, 1, -2, 2};
vi checky = {-3, 3, -3, 3, 0, 0};

int n, m;

bool is_valid(int x, int y){
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

void solve(){
    int r, c;
    cin >> r >> c;
    n = 4*r + 3, m = 6*c+3;
    vector<string> s(n);

    pii src, t;
    forn(i, n){
        cin >> s[i];
        forn(j, m){
            if(s[i][j] == 'S'){
                src= {i, j};
            }
            if(s[i][j] == 'T'){
                t = {i, j};
            }
        }
    }
    dist[src] = 1;
    queue<pii> q;
    q.push(src);
    cout << src.first << " " << src.second << endl;
    cout << "case" << endl;
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        forn(i, 6){
            int x = top.first + dx[i], y = top.second + dy[i];
            int cx = top.first + checkx[i], cy = top.second + checky[i];
            if(!is_valid(x, y) || !is_valid(cx, cy)){
                continue;
            }
            cout << s[x][y] << " " << s[cx][cy] << endl;
            if(i >= 4){
                // 2 tk cuoi
                if(s[cx][cy] == '-'){
                    continue;
                } else {
                    if(dist[{x, y}] == 0){
                        dist[{x, y}] = dist[top] + 1;
                        q.push({x, y});
                    }
                }
            } else {
                if(i >= 2){
                    if(s[cx][cy] == '\\'){
                        continue;
                    }
                    else {
                        if(dist[{x, y}] == 0){
                            dist[{x, y}] = dist[top] + 1;
                            q.push({x, y});
                        }
                    }
                } else {
                    if(s[cx][cy] == '/'){
                        continue;
                    } else {
                        if(dist[{x, y}] == 0){
                            dist[{x, y}] = dist[top] + 1;
                            q.push({x, y});
                        }
                    }
                }
            }   
        }
    }
    for(auto [p, dis] : dist){
        cout << p.first << " " << p.second << " " << dis << endl;
    }
    if(dist[t] == 0){
        cout << -1 << endl;
    } else {
        cout << dist[t] - 1 << endl;
    }
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

