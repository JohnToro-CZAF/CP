#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

ll gcd(ll x, ll y){
	ll ans = x;
	ll temp = y;
	while(ans != temp){
		if(ans < temp){ 
			temp -= ans;
		} else{
			ans -= temp;
		}
	}
	return ans;
}

ll lcm(ll x, ll y){
	return x*y/gcd(x, y);
}

void solve(){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	for(ll k = 0; k < (1<<n); k++){
		bool is[n];
		for(ll i = 0; i < n; i++){
			is[i] = false;
		}
		for(ll i = 0; i < n; i++){
			if(k & (1<<i)){
				is[i] = true;
			}
		}
		ll ans = 0;
		for(ll i = 0; i < n; i++){
			if(is[i]){
				ans += a[i];
			} else {
				ans -= a[i];
			}
		}
		if(ans % 360 == 0){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main(){
    solve();
}