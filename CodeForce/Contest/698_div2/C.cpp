#include<bits/stdc++.h>

using namespace std;

void solve(){
    long n;
    cin >> n;
    long m = 2*n;
    long long a[m];
    for(long  i= 0; i <m; i++){
        cin >> a[i];
    }
    sort(a, a+m);
    // for(int i = 0; i <m; i++){
    //     cout << a[i] << " ";
    // }
    // cout << "\n";
    if(n == 1){
        if(a[1] == a[0] && (a[0]&1)==0){
            cout << "YES" << endl;
            return;
        } else{
            cout << "NO" <<endl;
            return;
        }
    }
    long long b[n];
    for(long i = 0; i < m; i+=2){
        if(a[i] != a[i+1]){
            cout << "NO" << endl;
            // cout << "lom";
            return;
        }
        long temp = i/2;
        b[temp] = a[i];
    }
    long long sT = 0;
    long k = m;
    long long sum = b[0]/2;
    // for(int i = 0; i <n; i++){
    //     cout << b[i] << " ";
    // }
    // cout << "\n";
    long long c[n];
    for(int i = n-1; i >= 0; i--){
       if((b[i] - 2*sT)%(k) == 0){
           c[i] = (b[i] - 2*sT)/(k);
           k -= 2;
           if(c[i] <= 0){
               cout << "NO" << endl;
               return;
           }
           sT += c[i];
       }
       else{
           cout << "NO" <<endl;
        //    cout << "5";           
           return;
       }
    }
    sort(c, c+n);
    for(int i = 0; i < n-1; i++){
        if(c[i] == c[i+1]){
            cout << "NO" << endl;
            return;
        }
    }
    // cout << "\n";
    for(int i =0; i < n; i++){
        // cout << sum <<endl;
        sum -= c[i];
    }
    if(sum != 0){
        cout << "NO" << endl;
        // cout << "6";
        return;
    } else {
        // cout << "7";        
        cout << "YES" <<  endl;
    }

}

int main(){
    long c;
    cin >> c;
    while (c--)
    {
        solve();
    }
    
}
