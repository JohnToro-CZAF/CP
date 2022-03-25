#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;
    long long ans = 1;
    if((n%2) == 0){
        // cout << "case1";
        if((k%n) == 0){
            cout << n << endl;
            return;
        } else {
            cout << k%n << endl;
            return;
        }
    } else {
        // cout << "case2";
        long long t = n/2;
        long long l = (k-1)/t;
        ans = k+l;    
    }
    ans = ((ans%n) == 0) ? (n) : (ans%n);
    cout << ans << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}