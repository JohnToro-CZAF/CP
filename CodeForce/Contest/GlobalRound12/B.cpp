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
	ll ans = 0;
	ll n, u, v;
	cin >> n >> u >> v;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll i = 0; i < n-1; i++){
		ans = max(ans, abs(a[i+1] - a[i]));
	}
	if(ans > 1){
		cout << 0 << endl;
		return;
	}
	if(ans == 1){
		cout << min(u, v) << endl;
		return;
	}
	if(ans == 0){
		cout << min(u + v, 2*v) << endl;	
		return;
	}
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
