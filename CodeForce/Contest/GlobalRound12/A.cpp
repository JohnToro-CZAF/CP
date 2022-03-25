#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll a[template_size];
ll b[template_size];
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;

    return t;
}

void solve(){
	ll n, q;
	cin >> n >> q;
	ll z = 0;
	ll o = 0;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 0){
			z++;
		} else {
			o++;
		}
	}
	for(ll i = 0; i < q; i++){
		ll x, y;
		cin >> x >> y;
		if(x==1){
			if(a[y-1] == 0){
				a[y-1] = 1;
				o++;
				z--;
			} else{
				a[y-1] = 0;
				o--;
				z++;
			}
		}
		if(x == 2){
			if(y <= o){
				cout << 1 << endl;
			} else {
				cout << 0 << endl;
			}
		}
	}
}

int main(){
    solve();
}
