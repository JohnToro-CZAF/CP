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
    ll x,y,z,t;
    cin >> x >> y >> z >> t;
    ll ans;
    ans = min(cei(x, y)*y - x, cei(x, z)*z - x);
    ans = min(ans, cei(x, t)*t - x);
    cout << ans << endl;
}

int main(){
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
