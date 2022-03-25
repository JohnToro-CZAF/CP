#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n+3][m+3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if((i+j) % 2 == 0){
                if(a[i][j] % 2 == 1){
                    a[i][j]++;
                }             
            } else {
                if(a[i][j] % 2 == 0){
                    a[i][j]++;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}