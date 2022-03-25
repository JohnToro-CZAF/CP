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
int order[maxn+3];
bool visited[maxn];
vector<string> c(maxn);
int source;

int to(int i, int j){
    return i*m+j;
}
 
void dfs(int s, int prev){
    if( (s!=source && order[s] >= 2) || visited[s]){
        return;
    }
    visited[s] = true;
    must.push_back(s);
    int i = s/m;
    int j = s%m;
    if(i >= 1){
        if(c[i-1][j] == '.' || c[i-1][j] == 'L') {order[to(i-1, j)]--;}
    }
    if(i <= n-2){
        if(c[i+1][j] == '.' || c[i+1][j] == 'L') {order[to(i+1, j)]--;}
    }
    if(j >= 1){
        if(c[i][j-1] == '.' || c[i][j-1] == 'L') {order[to(i, j-1)]--;}
    }
    if(j <= m-2){
        if(c[i][j+1] == '.' || c[i][j+1] == 'L') {order[to(i, j+1)]--;}
    }
    for(auto &x : adj[s]){
        if(x == prev) continue;
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
        memset(order, 0, sizeof(order));
        memset(visited, false, sizeof(visited));
        forn(i, n){
            cin >> c[i];
        }
        forn(i, n){
            forn(j, m){
                if(c[i][j] == 'L') source = to(i, j);
                if(c[i][j] == '.' || c[i][j] == 'L'){
                    int coor = to(i,j);
                    if(i >= 1){
                        if(c[i-1][j] == '.' || c[i-1][j] == 'L') {adj[coor].push_back(to(i-1, j)); order[coor]++;}
                    }
                    if(i <= n-2){
                        if(c[i+1][j] == '.' || c[i+1][j] == 'L') {adj[coor].push_back(to(i+1, j)); order[coor]++;}
                    }
                    if(j >= 1){
                        if(c[i][j-1] == '.' || c[i][j-1] == 'L') {adj[coor].push_back(to(i, j-1)); order[coor]++;}
                    }
                    if(j <= m-2){
                        if(c[i][j+1] == '.' || c[i][j+1] == 'L') {adj[coor].push_back(to(i, j+1)); order[coor]++;}
                    }
                }
 
            }
        }
        dfs(source, -1);
        for(auto x : must){
            if(x == source) continue;
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