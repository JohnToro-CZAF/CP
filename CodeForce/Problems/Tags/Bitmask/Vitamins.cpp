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

struct duo {ll x; ll y;};

void solve(){
	ll n;
	cin >> n;
	vector<duo> v(n);
	for(ll i = 0; i < n; i++){
		ll t;
		string s;
		cin >> t >> s;
		ll k = 0;
		for(ll j = 0; j < s.size(); j++){
			if(s[j] == 'A') k +=4;
			if(s[j] == 'B') k += 2;
			if(s[j] == 'C') k+= 1;
		}
		duo temp = {t, k};
		v[i] = temp;
	}
	ll ans = inf;
	for(ll i = 0; i < n; i++){
		if(v[i].y == 7) ans = min(ans, v[i].x);
		else{
			for(ll j = i+1; j < n; j++){
				ll kk = v[i].y | v[j].y;
					if(kk == 7){
						ans = min(ans, v[i].x + v[j].x);
					} else {
						for(ll k = j+1; k < n; k++){
							ll t = (v[i].y | v[j].y) | v[k].y;
							if(t == 7){
								// cout << v[i].y << " " << v[j].y << " " << v[k].y << endl;
								ans = min(ans, v[i].x+v[j].x+v[k].x);
								// cout << i << " " << j <<" " << k << endl;
							}
						}
					}
			}
		}	
	}
	if(ans < inf) cout << ans << endl;
	else cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

