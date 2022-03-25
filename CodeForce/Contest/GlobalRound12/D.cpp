#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
	vector<ll> a;
	vector<ll> b;
	ll x,y;
	cin >> x >> y;
	if(x > y){
		cout << "NO" << endl;
		return;
	}
	if(x == y){
		cout << "YES" << endl;
		return;
	}
	for(ll i = 0; i < 30; i++){
		if(x&(1<<i)) a.push_back(i);
		if(y&(1<<i)) b.push_back(i);
	}
	if(a.size() < b.size()){
		cout << "NO" << endl;
		return;
	}
	for(ll i = 0; i < b.size(); i++){
		if(a[i] > b[i]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
