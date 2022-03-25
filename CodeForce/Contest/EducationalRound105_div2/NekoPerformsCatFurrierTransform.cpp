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

bool check(ll n){
	ll h = log(n)/log(2) + 1;
	if(n == (1<<h) - 1){
		return true;
	}
	return false;
}

struct duo
{
	ll a;
	ll b;
};

duo find(ll x){
	ll index;
	ll h = log(x)/log(2);
	// cout << h << endl;
	for(ll i = h-1; i >= 0; i--){
		ll cac = x & (1ll<<(i+1)) - 1;
		ll h1 = log(cac)/log(2);
		if(h1 < i){
			index = i;
			break;
		}
	}
	// cout << index + 1<< endl;
	ll t = (1ll<<(index+1)) - 1;
	// cout << t << " " << x << endl;
	ll ans = x^t;
	// cout << "cac" <<  ans << endl;
	return {ans, index+1};
}


void solve(){
	ll x;
	cin >> x;
	ll step = 0;
	vector<ll> v;
	if((x & 1) == 0){
		v.push_back(1);
		step+=2;
		x++;
	}
	while(!check(x)){
		duo temp = find(x);
		x = temp.a;
		// cout << x << endl;
		v.push_back(temp.b);
		x++;
		// cout << x << endl;
		step+=2; 
	}
	// cout << "start here" << endl;
	cout << step << endl;
	for(ll i = 0; i < v.size(); i++){
		cout << v[i] << " ";
	}		
	cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
 
}

