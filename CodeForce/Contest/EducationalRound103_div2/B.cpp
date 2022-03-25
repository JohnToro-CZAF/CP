#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

using ll = long long;
ll inf = LONG_MAX;

vector<ll> v; 
ll a[300006];
ll b[300006];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll ans = a[0];
    for(ll i = 1; i < n; i++){
        ans += max(0LL, cei(a[i]*100, k) - ans);
        ans += a[i];
    }
    cout << (ans - sum) << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}