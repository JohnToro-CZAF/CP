#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

// Returns factorial of n 
ll fact(ll n) 
{ 
    ll res = 1; 
    for (ll i = 2; i <= n; i++) 
        res = res * i; 
    return res; 
}

ll nCr(ll n, ll r) 
{ 
    return fact(n) / (fact(r) * fact(n - r)); 
} 
  
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
	string x,y;
	cin >> x >> y;
	ll xp = 0, yp = 0, yq = 0;
	long double ans;
	for(ll i = 0; i < x.size(); i++){
		if(x[i] == '+') xp++;
		if(y[i] == '+') yp++;
		if(y[i] == '?') yq++;
	}
	if(yp > xp){
		cout << 0 << endl;
		return;
	}
	if(abs(xp-yp) > yq) {cout << 0 << endl; return;}
	else {ans = nCr(yq, abs(xp-yp));}
	while(yq != 0){
		ans /= 2;
		yq--;
	}
	cout.precision(17);
	cout << fixed << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

