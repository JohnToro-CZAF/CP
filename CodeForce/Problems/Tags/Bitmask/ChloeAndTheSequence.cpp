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
		} else
		{
			ans -= temp;
		}
	}
	return ans;
}

ll lcm(ll x, ll y){
	return x*y/gcd(x, y);
}


void solve()
{
	ll n, k;
	cin >> n >> k;
	for (ll i = n; i >= 0; i--) {
		if (k >= (1LL << i)) {
			k -= (1LL << i);
			if (k == 0) {
				cout << (i+1) << endl;
				return;
			}
		}
	}
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}