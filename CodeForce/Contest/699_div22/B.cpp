#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    long long k;
    cin >> n >> k;
    long a[n];
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    if(k >= 10000){
        cout << "-1" << endl;
        return;
    }
    for(int i = 0; i < k; i++){
        long t = 0;
        for(int j = 0; j < n-1; j++){
            if((a[j+1] > a[j]) && i == k-1){
                cout << j+1 << endl;
                return;
            }
            if(a[j+1] > a[j]){
                a[j]++;
                // cout << "vc" << endl;
                // cout << a[j] << " "; 
                break;
            }
            if(a[j+1] <= a[j]){
                t++;
            }
        }
        if(t == n-1){
            cout << -1 << endl;
            return;
        }
        t = 0;
    }
    cout << -1 << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}