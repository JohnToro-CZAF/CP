#include<bits/stdc++.h>

using namespace std;

int n, e, s;
const int mxN = 1e6;
vector<int> a[mxN];
bool visited[mxN] = {false};

void dfs(int s, int b){
    if(visited[s]){
        return;
    }
    visited[s] = true;
    cout << b << "->" << s << endl;
    for(auto x : a[s]){
        dfs(x, s);
    }
}

int main(){
    cin >> n >> e >> s;
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(s, s);
}

