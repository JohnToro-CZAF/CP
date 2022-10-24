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


struct State{
    int map[7][7];
    int step;
};

void print(State x){
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=6; j++) {
            cout << x.map[i][j] << " ";

        }
        cout << endl;
    }
    cout << "Step = " << x.step << endl;
}

bool operator<(const State& a, const State& b)
{
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=6; j++) {
            if (a.map[i][j] != b.map[i][j])
                return a.map[i][j] < b.map[i][j];
        }
    }
    return a.map[0][0] < b.map[0][0];
}

int isValid(int x, int y) {
    return 1 <= x && x <= 6 && 1 <= y && y <= 6;
}

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void solve(){
    State old, next;
    for (int i=1; i<=6; i++)
        for (int j=1; j<=6; j++)
            cin >> old.map[i][j];

    old.step = 0;
    queue<State> q;
    q.push(old);
    set<State> visited;
    visited.insert(old);

    while (!q.empty()) {
        old = q.front(); q.pop();
        // print(old);
        if (old.map[3][6] == 1) {
            // cout << old.step << endl;
            if (old.step > 8) cout << "-1\n";
            else cout << old.step + 2 << "\n";
            return;
        }
        for (int i=1; i<=6; i++) {
            for (int j=1; j<=6; j++) {
                if (old.map[i][j] != 0) continue;
                for (int k=0; k<4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (!isValid(x,y) || old.map[x][y]==0)continue;
                    int xx = x + dx[k];
                    int yy = y + dy[k];

                    if (!isValid(xx,yy) || old.map[xx][yy]!=old.map[x][y]) continue;
                    if ( isValid(xx+dx[k], yy+dy[k]) && 
                        old.map[xx+dx[k]][yy+dy[k]] == old.map[xx][yy] ){
                                                xx += dx[k]; yy += dy[k];
                                        }
                    // cout << old.map[xx][yy] << endl;
                    // cout << "x = " << x << ", y = " << y << endl;
                    // cout << "xx= " <<xx << ", yy= " << yy << endl; 
                    next = old; 
                    next.step++;
                    swap(next.map[i][j], next.map[xx][yy]);

                    if (next.step <= 10 && visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
    }

    cout << "-1\n";
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

