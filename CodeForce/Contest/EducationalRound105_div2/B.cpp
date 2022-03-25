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

void solve(){
	ll a[7];
	ll n;
	ll cnt = 0;
	ll fre = 0;
	cin >> n;
	for(ll i = 1; i <= 4; i++){
		cin >> a[i];
		if(a[i] == n){
			cnt++;
		}
		if(a[i] == n-1){
			fre++;
		}
	}
	a[5] = a[1];
	a[6] = a[2];
	if(cnt == 0 && fre == 3){
		cout << "NO" << endl;
		return;
	}
	if(cnt == 1){
		for(ll i = 1; i <= 4; i++){
			if(a[i] == n){
				if(a[i+1] == 0 && a[i-1] == 0){
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	if(cnt == 2){
		for(ll i = 1; i <= 4; i++){
			if(a[i] == a[i+2] && a[i] == n){
				if(a[i-1] < 2 || a[i+1] < 2){
					cout << "NO" << endl;
					return;
				}
			}
		}
		for(ll i = 1; i <= 4; i++){
			if(a[i] == a[i+1] && a[i] == n){
				if(a[i-1] < 1 && a[i+2] < 1){
					cout << "NO" << endl;
					return;
				}
			}
		}
	}
	if(cnt == 3){
		for(ll i = 1; i <= 4; i++){
			if(a[i] != n){
				if(a[i] < 2){
					cout << "NO" <<endl;
					return;
				}
			}
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