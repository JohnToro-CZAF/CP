#include<bits/stdc++.h>

using namespace std;

int find(int a[], int i, int j, int dis[], int n){
    if(i >= j){
        return i;
    }
    int l = 0;
    for(int k = i; k <= j; k++){
        l = max(l, a[k]);
    }
    cout << l << endl;
    int index;
    for(int k = i; k <= j; k++){
        if(a[k] == l){
            index = k;
            cout << index << "ha ha" << endl;
        }
    }
    int left, right;
    if(index == i){
        left = n;
        dis[left] = dis[index]++;
    } else {
        left = find(a, i, max(index-1, i), dis, n);
        dis[left] = dis[index]++;
    }
    if(index == j){
        right = n;
        dis[right] = dis[index]++;
    } else {
        right = find(a, min(index+1, j), j, dis, n);
        dis[right] = dis[index]++;
    }
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    // return; 
    // cout << " false "; 
    int dis[n+1];
    for(int i = 0; i <n+1; i++){
        dis[i] = 0;
    }
    // cout << " false "; 
    find(a, 0, n-1, dis, n);
    for(int i = 0; i <n; i++){
        cout << dis[i] << " " << endl;
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}