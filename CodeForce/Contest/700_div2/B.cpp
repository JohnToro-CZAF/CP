#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll a[template_size];
ll b[template_size];
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
    ll A, B, n;
    cin >> A >> B >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    ll sum = 0;
    ll ans = -10000006;
    for(ll i = 0; i< n; i++){
        sum += cei(b[i], A)*a[i];
    }
    // cout << sum << endl;
    for(ll i = 0; i < n; i++){
        ll t = (b[i]/A);
        ans = max(ans, B - sum + a[i]);
        // cout << B - sum + b[i] - t*A << endl;
    }
    // cout << ans << endl;
    (ans > 0) ? puts("YES") : puts("NO");
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}