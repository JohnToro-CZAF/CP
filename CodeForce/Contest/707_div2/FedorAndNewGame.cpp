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

ll power(ll base, ll powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
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
    ll n;
    cin >> n;
    ll a[n+1], b[n+1];
    ll tm[n];
    b[0] = 0;
    a[0] = 0;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        cin >> b[i];
    }	
    for(ll i = 0; i < n; i++){
        cin >> tm[i];
    }
    ll temp = 0;
    for(ll i = 0; i < n; i++){
        ll t = b[i+1] - a[i+1];
        temp += (tm[i] + (a[i+1]- b[i]));
        if(i == n-1){
            cout << temp << endl;
        }
        temp += cei(t, 2);
        temp = max(temp, b[i+1]);
        // cout << temp << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
