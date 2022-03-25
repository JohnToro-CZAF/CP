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

ll power(ll base, ll powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> v;
	for(ll i = 0; i < n; i++){
		ll t; cin >> t;
		v.push_back(t);
	}
	sort(v.rbegin(), v.rend());
	const ll size = log(v[0])/log(k);
	ll a[n+2][size+2];
	for(ll i = 0; i < n; i++){
		for(ll j = size+1; j >= 0; j--){
			ll p = power(k, j);
			ll temp = v[i]/p;
			a[i][j] = temp;
			v[i] -= temp*p;
		}
	}
	bool ans = true;
	for(ll j = 0; j <= size+1; j++){
		ll sum = 0;
		for(ll i = 0; i < n; i++){
			sum += a[i][j];
		}
		if(sum > 1){
			ans = false;
		}
	}
	if(ans){
		cout << "YES" << endl;
	} else{
		cout << "NO" << endl;
	}
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