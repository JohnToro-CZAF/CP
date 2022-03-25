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
	ll n, k;
	cin >> n >> k;
	ll m = n - k;
	for(ll i = 1; i < k - m; i++){
		cout << i << " ";
	}
	for(ll i = k; i >= k - m; i--){
		cout << i << " ";
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