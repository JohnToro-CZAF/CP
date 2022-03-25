#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
	ll n,q;
	string s;
	cin >> n >> q;
	cin >> s;
	ll res_r = 0;
	ll res_r_max = 0;
	ll res_r_min = 0;
	ll v[3][n+1];
	v[0][0] = 0;
	v[1][0] = 0;
	v[2][0] = 0;
	for(ll i = 0; i < n; i++){
		if(s[i] == '-'){
			res_r--;
		}
		if(s[i] == '+'){
			res_r++;
		}
		res_r_max = max(res_r_max, res_r);
		res_r_min = min(res_r_min, res_r);
		v[0][i+1] = res_r_max;
		v[1][i+1] = res_r_min;
		v[2][i+1] = res_r;
	}
	ll range[2][n+1];
	range[0][n] = 0;
	range[1][n] = 0;
	for(ll i = n-1; i >= 0; i--){
		if(s[i] == '-'){
			ll M = max(0ll, range[0][i+1] - 1);
			ll m = min(0ll, range[1][i+1] - 1);
			range[0][i] = M;
			range[1][i] = m; 
		} else {
			ll M = max(0ll, range[0][i+1] + 1);
			ll m = min(0ll, range[1][i+1] + 1);
			range[0][i] = M;
			range[1][i] = m; 
		}
	}
	for(ll i = 0; i < q; i++){
		ll x, y;
		cin >> x >> y;
		// cout << range[0][y] << " " << v[2][x-1] << " " << v[0][x-1] << endl;
		// cout << range[1][y] << " " << v[2][x-1] << " " << v[1][x-1] << endl;
		ll M = max(range[0][y]+v[2][x-1], v[0][x-1]);
		ll m = min(range[1][y]+v[2][x-1], v[1][x-1]);
		cout << M - m +1 <<endl;
	}
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}