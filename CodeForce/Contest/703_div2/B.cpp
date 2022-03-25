#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long x[n];
    long long y[n];
    for(int i = 0; i <n; i++){
        cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    long long ans = 0;
    long long xa = 0;
    long long ya = 0;
    if(n%2 == 0){
        long long t = n/2;
        xa = x[t] - x[t-1] + 1;
        ya = y[t] - y[t-1] + 1;
        ans = xa*ya;
    } else {
        ans = 1;
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