#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0 ;i <n; i++){
        cin >> a[i];
    }
    long long sum = 0;
    bool c = true;
    for(int i = 1; i <= n; i++){
        sum += a[i-1];
        if(sum < i*(i-1)/2){
            c = false;
        }
    }
    if(c){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}