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
	ll ans = 0;
	for(ll k = 0; k <= 30; k++){
		ll temp = 0;
		for(ll i = 0; i < n; i++){
			if(a[i] >= (1<<k) && a[i] < (1<<(k+1))){
				temp++;
			}
		}
		(temp) ? (ans += temp*(temp-1)/2) : (ans += 0);
	}
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}