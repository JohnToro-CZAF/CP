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
	ll n, k;
	cin >> n >> k;
	ll t = log(n)/log(2);
	// cout << t;
	ll ans = (1ll<<(t+1)) - 1;
	// cout << ans << endl;
	// cout << t << endl;
	if(n == 1 && k == 1){
		cout << 1 << endl;
		return;
	}
	// cout << (1ll<<t)+1 << endl;
	if(k == 1 || n == (1ll<<t)-1){
		cout << n << endl;
		return;
	}
	if(k > 1){
		cout << ans << endl;
		return;
	}
}

int main(){
    solve();
}