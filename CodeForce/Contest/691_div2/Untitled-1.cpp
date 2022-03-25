#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll a[template_size][template_size][template_size];
ll b[template_size];
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;

    return t;
}

void solve(){
	ll n;
	cin >> n;
	for(ll i = 0; i < 10; i++){
		for(ll j = 0; j < n; j++){
			for(ll k = 0; k < n; k++){
				a[i][j][k] = 0;
			}
		}
	}
	for(ll i = 0; i < n; i++){
		string s;
		cin >> s;
		for(ll j = 0; j < n; j++){
			ll t = s[j] - '0';
			a[t][i][j] = 1;
		}
	}
	ll ans[10];
	for(ll i = 0; i < 10; i++){
		ans[i] = 0;
	}
	for(ll i = 0; i < 10; i++){
		for(ll j = 0; j < n; j++){
			vector<ll> t;
			for(ll k = 0; k < n; k++){
				if(a[i][j][k] == 0){
					continue;
				} else {
					t.push_back(k);
				}
			}
			if(t.size() == 0){
				continue;
			}
			if(t.size() == 1){
				ans[i] = max(ans[i], 0LL);
			}
			if(t.size() > 1){
				ll area = abs(t.back() - t.front())*max(abs(j - 0), abs(j - n));
				ans[i] = max(ans[i], area);
			}
		}
	}
	for(ll i = 0; i < 10; i++){
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
