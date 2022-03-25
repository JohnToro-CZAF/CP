#include<bits/stdc++.h>

using namespace std;
void  bfs(vector<int> a[], int n, int s, int dis[]){
    queue<int> q;
    bool visited[n];
    for(int i = 0; i <n; i++){
        visited[i] = false;
        dis[i] = 0;
    }
    q.push(s);
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        visited[t] = true; 
        for(auto x : a[t]){
            if(visited[x]){
                continue;
            } else {
                dis[x] = dis[t] + 1;
                q.push(x);
            }
       }
    }
}

int find(int b[], int i, int j, vector<int> *a){
    if(i == j){
        return b[i];
    }
    int l = 0;
    for(int k = i; k <= j; k++){
        l = max(l, b[k]);
    }
    int index;
    for(int k = i; k <=j ; k++){
        if(b[k] == l){
            index = k;
        }
    }
    int left = find(b, i, max(i, index-1), a);
    int right = find(b, min(index+1, j), j, a);
    a[index].push_back(left);
    a[index].push_back(right);
}

void solve(){
    int n;
    cin >> n;
    int b[n];
    vector<int> a[n];
    for(int i = 0; i <n; i++){
        cin >> b[i];
    }
    int s = 0;
    for(int i = 0; i < n; i++){
        s = max(b[i], s);
    }
    find(b, 0, n-1, a);
    int dis[n];
    bfs(a, n, s, dis);
    for(int i = 0; i < n; i++){
        cout << dis[i] << " ";
    }
    cout << "\n";
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}