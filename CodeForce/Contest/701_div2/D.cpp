#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0)
       return a;
    return gcd(b, a % b); 
}

void solve(){
    long long n, m;
    cin >> n >> m;
    long long a[1000][1000];
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    long long t = 1;
    for(long long i = 1; i < 17; i++){
        t = t*i/gcd(t, i);
    }
    for(long long i = 0; i <n; i++){
        for(long long j = 0; j < m; j++){
            if((i+j) % 2 == 1){
                a[i][j] = t;
            } else {
                a[i][j] = t + a[i][j]*a[i][j]*a[i][j]*a[i][j];
            }
        }
    }
    for(long long i = 0; i <n; i++){
        for(long long j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    // cout << t;
}

int main(){
    solve();
}