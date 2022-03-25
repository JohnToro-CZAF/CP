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
	const ll size = log(v[0])/log(k) + 9;
	cout << size << endl;
	ll a[n+3][size+3];
	for(ll i = 0; i < size; i++){
		for(ll j = 0; j  <size; j++){
			a[i][j] = 0;
		}
	}
	for(ll i = 0; i < n; i++){
		for(ll j = size; j >= 0; j--){
			ll p = power(k, j);
			ll temp = v[i]/p;
			// cout << temp << " ";
			a[i][j] = temp;
			cout << a[i][j] << " ";
			v[i] -= temp*p;
		}
		cout << "\n";
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j <= size; j++){
			cout << a[i][j] << " "; 
		}
		cout << "\n";
	}
	bool ans = true;
	for(ll j = 0; j <= size; j++){
		ll sum = 0;
		for(ll i = 0; i < n; i++){
			sum += a[i][j];
			// cout << a[i][j] << " ";
		}
		if(sum > 1){
			ans = false;
		}
		cout << "\n";
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

