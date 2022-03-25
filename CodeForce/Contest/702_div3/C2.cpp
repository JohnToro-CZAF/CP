#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    for(long long i = 1; i*i*i < n; i++){
        long long t = n - i*i*i;
        long long h = cbrtl(t);
        if(h*h*h == t){
            cout << "YES" << endl;;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}