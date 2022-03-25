#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

void solve(){
    int n;
    cin >>n;
    long long a[n+1];
    int b[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0){
            b[i] = -1;
        } else {
            b[i] = 1;
        }
    }
    b[n] = 0;
    long long ans = 0;
    long long N = 0;
    long long M = LONG_MAX;
    for(int i = 1; i < n+1; i++){
        if((b[i] == 1 && b[i-1] == -1) || (b[i] == 0 && b[i-1] == -1)){
            M = min(M, abs(a[i-1]));
            ans -= M;
            // cout << "th1" << endl;
            // cout << i << " " <<  ans << endl;
            M = LONG_MAX;
        }
        if((b[i] == -1 && b[i-1] == 1) || (b[i] == 0 && b[i-1] == 1)){
            N = max(N, a[i-1]);
            ans += N;
            // cout << "th2" << endl;
            // cout << i << " " << ans << endl;
            N = 0;
        }
        if(b[i-1] == 1 && b[i] == 1){
            N = max(N, a[i-1]);   
        }
        if(b[i-1] == -1 && b[i] == -1){
            M = min(M, abs(a[i-1]));
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