#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long x,y;
    cin >> x >> y;
    long long ans = 0;
    for(int i = 1; i*i < x; i++){
        long long up = (x/i) - 1;
        ans += max(0LL, min(up, y) - i);
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