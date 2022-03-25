#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n,m;
    cin >> n >> m;
    long long a[n], b[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    sort(a, a+n);
    long long ans = 0;
    int t = 0;
    for(int i = n-1; i >= 0; i--){
        if(t <= a[i]-1){
            ans += b[t];
            t++;
        } else {
            ans += b[a[i]-1];
        } 
    } 
    cout << ans << endl;
}

int main(){
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}