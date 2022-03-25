#include<bits/stdc++.h>

using namespace std;

long long q, n;
long long k;

void solve(){
    cin >> n >> q >> k;
    long long a[n+2];
    a[0] = 0;
    a[n+1] = k+1;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long dp[n];
    long long dp1[n];
    long long dp2[n];
    long long dp3[n];
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i] = a[i+2] - a[i] - 2;
            dp1[i] = 0;
            dp2[i] = a[n+1] - a[i] -2;
        }
        if(i == 0){
            dp[i] = a[i+2] - a[i] - 2;
            dp1[i] = a[i+2] - a[0] - 2;
            dp2[i] = 0;
        }
        dp[i] = a[i+2] - a[i] - 2;
        // cout << dp[i] << " ";
        dp1[i] = a[i+2] - a[0] - 2;
        dp2[i] = a[n+1] - a[i] -2;
        sum += dp[i];
        dp3[i] = sum;
    }
    while(q--){
        long long i, j;
        cin >> i >> j;
        long long ans = 0;
        if(i == j){
            cout << k-1 << endl;
            continue;
        }
        ans += (dp3[j-2] - dp3[i-1]);
        ans += dp1[i-1];
        ans += dp2[j-1];
        cout << ans << endl;
    }
}

int main(){
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);
    solve();
}