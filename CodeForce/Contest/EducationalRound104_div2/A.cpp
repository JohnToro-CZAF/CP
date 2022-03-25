#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == a[0]){
            count++;
        }
    }
    cout << n - count <<endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}