#include<bits/stdc++.h>
#include<limits.h>

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)

const int maxn = 2e5+13;

vector<vector<pair<int, int> > > v(maxn);

int a[2]; 
int color[maxn];
bool ok = true;

void dfs(int node){
    int co = color[node];
    a[co]++;
    for(auto &x : v[node]){
        int w = x.second;
        if(color[x.first] == -1){
            color[x.first] = co^w;
            dfs(x.first);
        } else {
            if(color[x.first] != co^w){ok = false;}
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        int n, m;
        cin >> n >> m;
        forn(i, n+5){
            v[i].clear();
            color[i] = -1;
        }
        forn(i, m){
            int x, y;
            string s;
            cin >> x >> y >> s;
            if(s == "crewmate"){
                v[x].push_back(make_pair(y, 0));
                v[y].push_back(make_pair(x, 0));
            }
            if(s == "imposter"){
                v[x].push_back(make_pair(y, 1));
                v[y].push_back(make_pair(x, 1));
            }
        }
        ok = true;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(color[i] == -1){
                color[i] = 0;
                a[0] = a[1] = 0;
                dfs(i);
                ans += max(a[0], a[1]);
            }
        }
        if(ok)cout << ans << endl;
        else cout << -1 << endl;
    }
}

