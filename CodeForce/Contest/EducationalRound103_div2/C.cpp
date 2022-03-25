#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v; 
ll a[template_size];
ll b[template_size];
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
    ll n;
    ll x;
    cin >> n;
    for(ll i = 0 ; i < n; i++) cin >> c[i];
    for(ll i = 0 ; i < n; i++) cin >> a[i];
    for(ll i = 0 ; i < n; i++) cin >> b[i];
    ll tot = c[n-1];
    ll ans = 0;
    for(ll i = n-1; i >= 1; i--){
        tot += 2;
        if(a[i] > b[i]){swap(a[i], b[i]);}
        ans = max(ans, tot + b[i] - a[i] - 1);
        if(a[i] == b[i]){
            tot = c[i-1];
        } else {
            tot += ((c[i-1] - b[i]) + a[i] - 1);
        }
        tot = max(tot, c[i-1]);
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