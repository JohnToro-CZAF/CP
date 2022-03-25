#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int maxn = 2e5 + 5;

vector<int> L[2];
vector<vector<int> > g;
int ans[maxn];
int msb[maxn];
void dfs(int now, int pre, int lvl){
    L[lvl].push_back(now);
    for(int v: g[now]){
        if(v == pre) 
            continue;
        dfs(v, now, lvl^1); // flip bit
    }
}
int main(){
    IOS;
    int c;
    cin >> c;
    for(int i = 1; i <= maxn; i++){
        for(int j = 17; j >=0; j--){
            if(i & (1<<j)) {msb[i] = j; break;}
        }
    }
    while(c--){
        int n;
        cin >> n;
        g.assign(n+1, vi(0));
        L[0].clear(); L[1].clear();
        for(int i = 0; i < n-1; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0,0);
        vector<int> clas[18];
        for(int i = 1; i<=n; i++){
            clas[msb[i]].push_back(i);
        }
        for(int j = 17; j >= 0; j--){
            int cur = 0;
            if(L[cur^1].size() > L[cur].size()){
                cur ^= 1;
            } // since two set |L[0]: black color| + |L[1] white color| = n
            // so we can "push" every element in each class to either color.
            for(int i = 0; i < clas[j].size(); i++){
                int a = L[cur].back();
                L[cur].pop_back();
                ans[a] = clas[j][i];
            }
        }
        for(int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        }   
}

