#include<bits/stdc++.h>

using namespace std;

void solve(){
    long n, k;
    cin >> n >> k;
    long long a[n];
    for(long i = 0; i < n; i++){
        cin >> a[i];
    }
    long long sum = 0;
    long long m = 0;
    for(long i = 1; i < n; i++){
        if((double)100*a[i]/k > (double)sum){
            sum += a[i-1];
            long long temp = (long long)(100*a[i]+k-1)/k - sum;
            sum += temp;
            m +=temp;
        } else {
            continue;
        }
    }
    cout << m << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}