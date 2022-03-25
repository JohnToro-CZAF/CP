#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll b[template_size];
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
	ll a[template_size];
	ll n, d;
	cin >> n >> d;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	if(n == 1){
		if(a[0] <= d){
			cout << "YES" << endl;
			return;
		} else {
			cout << "NO" << endl;
			return;
		}
	}
	if(a[n-1] <= d){
		cout << "YES" << endl;
		return;
	}
	if(a[0] + a[1] <= d){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
