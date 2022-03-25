#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

using ll = long long;
ll inf = LONG_MAX;

vector<ll> v; 
ll a[300006];
ll b[300006];

void solve(){
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    if(x == y){
        cout << 2*x << endl; 
        return;
    }
    ans = 2*min(x,y) + 2*(max(x,y)- min(x,y) - 1) + 1;
    cout << ans << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}