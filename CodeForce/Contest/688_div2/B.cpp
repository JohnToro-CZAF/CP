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
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	if( n == 1){
		cout << 0 << endl;
		return;
	}
	ll sum = 0;
	for(ll i = 0; i < n-1; i++){
		sum += abs(a[i] - a[i+1]);
	}
	ll ans = 9223372036854775807;
	for(ll i = 1; i < n-1; i++){
		ans = min(ans, sum - (abs(a[i] - a[i-1]) + abs(a[i] - a[i+1]) - abs(a[i+1] - a[i-1])));
	}
	ans = min(ans, sum - abs(a[0] - a[1]));
	ans = min(ans, sum - abs(a[n-1] - a[n-2]));
	cout << ans << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
