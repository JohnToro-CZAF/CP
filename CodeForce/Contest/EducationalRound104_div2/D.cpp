#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long ans = 0;
    if(n < 5){
        cout << 0 << endl;
        return;
    }
    // if(n < 5){
    //     cout << 0 << endl;
    // }
    for(long long i = 3; i*i <= 2*n-1; i++){
        if(i % 2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}