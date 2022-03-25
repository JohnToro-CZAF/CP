#include<bits/stdc++.h>

using namespace std;

bool isPerfectSquare(long long x)
{
    if (x >= 0) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }

    return false;
}


void solve(){
    long long n;
    cin >> n;
    if(n == 999999999999){
        cout << "NO" << endl;
        return;
    }
    long long s = sqrt(n);
    vector<long long> v;
    for(long long i = 2; i <= s+1; i++){
        if((n % i) == 0){
            v.push_back(i);
        }
        // cout << i << endl;
    }
    // for(auto x : v){
    //     cout << x << endl;
    // }
    for(auto x : v){
        long long temp;
        // cout << x;
        if(x*x*x == n){
            continue;
        }
        if(((4*n/x) - x*x)%3 == 0){
            temp = ((4*n/x) - x*x)/3;
        } else {
            continue;
        }
        // cout << x << " " << temp << endl;
        // cout << x << " " << temp << endl;
        if(isPerfectSquare(temp)){
            cout << "YES" << endl;
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