#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
#define forn(i,n) for(int i=0;i<n;++i)
 
const int maxn = 1e6 + 5;
 
vvi adj(maxn);
int n, m;
vi must;
bool visited[maxn];

int to(int i, int j){
    return i*m+j;
}
 
void dfs(int s, int prev){
    if(int(adj[s].size()) >= 3){
        return;
    }
    must.push_back(s);
    for(auto &x : adj[s]){
        if(x == prev || !visited[x]) continue;
        visited[x] = true;
        dfs(x, s);
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i = 0; i < n*m; i++){
            adj[i].clear();
        }
        must.clear();
        char c[n+3][m+3];
        memset(visited, false, sizeof(visited));
        memset(c, ' ', sizeof(c));
        forn(i, n){
            forn(j, m){
                cin >> c[i][j];
            }
        }
        int s;
        forn(i, n){
            forn(j, m){
                if(c[i][j] == 'L') s = i*m+j;
                if(c[i][j] == '.' || c[i][j] == 'L'){
                    int coor = to(i,j);
                    if(i >= 1){
                        if(c[i-1][j] == '.') {adj[coor].push_back(to(i-1, j));}
                    }
                    if(i <= n-2){
                        if(c[i+1][j] == '.') {adj[coor].push_back(to(i+1, j));}
                    }
                    if(j >= 1){
                        if(c[i][j-1] == '.') {adj[coor].push_back(to(i, j-1));}
                    }
                    if(j <= m-2){
                        if(c[i][j+1] == '.') {adj[coor].push_back(to(i, j+1));}
                    }
                }
 
            }
        }
        dfs(s, -1);
        for(auto x : must){
            if(x == s) continue;
            c[x/m][x%m] = '+';
        }
        forn(i, n){
            forn(j, m){
                cout << c[i][j];
            }
            cout << "\n";
        }
    }
}