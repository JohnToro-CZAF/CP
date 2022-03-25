#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

using ll = long long;
ll inf = LONG_MAX;

vector<ll> v; 
ll a[300006];
ll b[300006];

void solve(){
    ll n;
    cin >> n;
    ll sum = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a+n);
    ll ans = inf;
    for(ll i = 0; i < n; i++){
        ll t = (n-2+sum-a[i])/(n-1);
        ll k = max(t, (ll)((a[i]+n-2)/(n-1)));
        cout << k << endl;
        ans = min(ans, (n-1)*k - a[i]);
        cout << ans << endl;
    }
    cout << ans << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}