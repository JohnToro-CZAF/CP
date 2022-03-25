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
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}	
	for(ll i = 0; i < m; i++){
		cin >> b[i];
	}
	sort(a, a+n);
	sort(b, b+m);
	ll ans = 0;
	ll i = 0, j = 0;
	while(i < n && j < m){
		if(a[i] > b[j]){
			j++;
			continue;
		}
		if(a[i] < b[j]){
			i++;
			continue;	
		}
		if(a[i] == b[j]){
			ans++;
			i++;
			j++;
			continue;
		}
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
