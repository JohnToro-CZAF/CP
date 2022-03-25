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
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }	
    ll b[n];
    memset(b, 0, sizeof(b));
    for(ll i = 0; i < n; i++){
        ll index = min(a[i], i);
        if(index > 0){
            b[i - index] = 1;
        }
        // cout << ((1ll<<a[i]) - 1) << endl;
    }
    for(ll i = 0; i < n; i++){
        cout << b[i] << " ";
    }
    // for(ll i = n-1; i >= 0; i--){
    //     if(temp & (1ll<<i)){
    //         cout << 1 << " ";
    //     } else {
    //         cout << 0 << " ";
    //     }
    // }

    cout << "\n";
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
