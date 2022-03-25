#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)

ll findSum(ll n){
    ll x = sqrt(2*n);
    if(x*(x+1)/2 == n){
        return x;
    } else if(n > x*(x+1)/2 && n < (x+1)*(x+2)/2){
        return x+1;
    } else if(n == (x+1)*(x+2)/2){
        return x+1;
    } else if(n == (x-1)*x/2){
        return x-1;
    } else if(n > x*(x-1)/2 && n < x*(x+1)/2){
        return x;
    }
    // return x;
}

ll findsum1(ll n){
    ll x = sqrt(2*n);
    if(x*(x+1)/2 == n){
        return x;
    } else if((x+1)*(x+2)/2 == n){
        return x+1;
    } else if((x-1)*x/2 == n){
        return x-1;
    } else if(x*(x-1)/2 < n && x*(x+1)/2 > n){
        return x-1;
    } else if(n > x*(x+1)/2 && n < (x+1)*(x+2)/2){
        return x;
    }
}

void solve(){
    ll k, x;
    cin >> k >> x;
    ll ans = 0;
    if(x >= k*k){
        cout << ans + 2*k-1 << endl;
        return;
    }
    ll sumf = k*(k+1)/2;
    if(x > sumf){
        ans += k;
        ll temp = k*k - x;
        ans += k-1-findsum1(temp);

    } else if(x == sumf){
        cout << k << endl;
        return;
    } else {
        ans += findSum(x);

    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

