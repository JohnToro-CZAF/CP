#include<bits/stdc++.h>

using namespace std;

int a[1000003], b[1000003];

void rec(int l, int r, int d){
    if(l > r){
        return;
    }
    int p = l;
    for(int i = l; i <= r; i++){
        if(a[i] > a[p]){
            p = i;
        }
    }
    b[p] = d;
    rec(l, p-1, d+1);
    rec(p+1, r, d+1);
}

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    rec(0, n-1, 0);
    for( int i = 0; i <n; i++){
        cout << b[i] << " ";
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}