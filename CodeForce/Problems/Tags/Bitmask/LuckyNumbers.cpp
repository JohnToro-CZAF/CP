#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

struct tuple {ll x; ll y; ll z;};

ll inf = 100000000000000;

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
	return ans}

ll lcm(ll x, ll y){
	return x*y/gcd(x, y);
}

ll ans = inf;

void find(ll a, ll b, ll c, ll n){
	if(a == b && a > 0 && c >= n){
		ans = min(ans, c);
	}
	if(c > 10000000000){
		return;
	}
	find(a+1, b, c*10+7, n);
	find(a, b+1, c*10+4, n);
}

void solve(){
	ll n;
	cin >> n;
	find(0, 0, 0, n);
	cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}






