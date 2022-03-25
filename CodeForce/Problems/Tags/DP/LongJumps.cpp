#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long a[n+3];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    long long dp[n+3];
    for(int i = 0; i < n; i++){
        dp[i] = a[i];
    }
    for(int i = n-1; i >= 0; i--){
        if(i+a[i] <= n-1){
            dp[i] += dp[i+a[i]] ;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, dp[i]);
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