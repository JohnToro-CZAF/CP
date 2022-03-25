#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin >> n;
    long long a[n];
    for(long long i = 0; i < n; i++){
        long long t = (i*(n-1)) % n;
        a[t] = i;
        // cout << t << " " << i<< endl;
    }
    // cout << " cut" << endl;
    long long b[n];
    cin >> b[0];
    if(n == 1){
        cout << 1 << " " << 1 << endl;
        cout << 0 - b[0] << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 <<endl;
        cout << 0;
        return;
    }
    if(n == 2){
        cin >> b[1];
        cout << 1 << " " << 1 << endl;
        cout << 0 - b[0] << endl;
        cout << 2 << " " << 2 << endl;
        cout << 0 - b[1] << endl;
        cout << 1 << " " << 2 <<endl;
        cout << 0 << " " << 0;
        return;
    }
    cout << 1 << " " << 1 << endl;
    cout << 0 - b[0] << endl;
    b[0] = 0;
    cout << 2 << " " << n << endl;
    for(long long i = 1; i<n; i++){
        cin >> b[i];
        long long g = (b[i] % n < 0) ? (b[i]%n + n) : (b[i]%n);
        g = (g==0) ? 0 : (n-g); 
        // cout << g << endl;
        cout << a[g]*(n-1) << " ";
        b[i] += a[g]*(n-1);
    }
    cout << "\n";
    cout << 1 << " " << n << endl;
    for(long long i = 0; i <n; i++){
        cout << 0-b[i] <<" ";
    }
}

int main(){
    solve();
}