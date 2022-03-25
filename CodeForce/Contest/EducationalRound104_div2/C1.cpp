#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        int k = (n-1)/2;
        int j = 1;
        while(k--){
            int t = (i+j)%n;
            a[i][t] = 1;
            a[t][i] = -1;
            j++;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            cout << a[i][j] << " ";
        }
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