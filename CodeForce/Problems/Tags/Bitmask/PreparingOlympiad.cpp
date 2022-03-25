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
	ll n, l, r, x;
    cin >> n >> l >> r >> x;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll ans = 0;
    // cout << (1<<n) << endl;
    for(ll i = 0; i < (1ll<<n); i++){
        ll left = inf, right = 0;
        ll sum = 0;
        ll num = 0;
        for(ll j = 0; j < n; j++){
            if((1ll<<j) & i){
                left = min(left, a[j]);
                right = max(right, a[j]);
                num++;
                sum += a[j];
            }
        }
        if(num >= 2 && left != inf && right != 0){
            if(sum <= r && sum >= l){
                if((right - left) >= x){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
