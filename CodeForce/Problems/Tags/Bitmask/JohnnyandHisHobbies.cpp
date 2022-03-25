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


bool check(ll k, ll a[], bool chk[], ll n){
	for(ll i = 0; i < n; i++){
		if(!chk[k ^ a[i]]){
			return false;
		}
	}
	return true;
}

void solve(){
	ll n;
	cin >> n;
	bool chk[1024];
	ll a[n];
	for(ll i = 0; i < 1024; i++){
		chk[i] = false;
	}
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		chk[a[i]] = true;
	}
	if(n % 2 == 1){
		cout << -1 << endl;
		return;
	}
	for(ll k = 1; k < 1024; k++){
		if(check(k, a, chk, n)){
			cout << k << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
} 