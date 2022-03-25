#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n][n];
    int w[n];
    int l[n];
    for(int i = 0; i < n; i++){
        w[i] = 0;
        l[i] = 0;
        for(int j = 0; j <n; j++){
            a[i][j] = 0;
        }
    }
    if((n%2) == 0){
        int k = n/2;
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                if(w[i] < k-1 && l[j] < k-1 && a[i][j] == 0){
                    a[i][j] = 1;
                    a[j][i] = -1;
                    w[i]++;
                    l[j]++;
                }
                if(l[i] < k-1 && a[i][j] == 0){
                    a[i][j] = -1;
                    a[j][i] = 1;
                    l[i]++;
                    w[j]++;
                }
                if(l[i] == k-1 && w[i] == k-1 && a[i][j] == 0){
                    a[i][j] = 2;
                    a[j][i] = 2;
                } 
            }
        }
        
    } else {
        
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <n; j++){
            cout <<  a[i][j] << endl;
        }
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}