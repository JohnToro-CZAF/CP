#include<bits/stdc++.h>

using namespace std;

int power(int n){
    int ans = (int)(log(n)/log(2));
    return ans;
}

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0;i<n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    for(int i = 0; i < n-1;i++){
        int x = max(a[i], a[i+1]);
        int y = min(a[i], a[i+1]);
       while(x > 2*y){
           y *=2;
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