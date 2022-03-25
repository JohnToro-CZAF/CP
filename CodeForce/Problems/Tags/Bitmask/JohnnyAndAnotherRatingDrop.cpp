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
	unsigned long long n;
    cin >> n;
    unsigned long long ans = 0;
    ll h = log(n)/log(2)+1;
    // cout << h << " ";
    unsigned long long a[70];
    a[0] = 1;
    for(ll i = 1; i < 63; i++){
        a[i] = a[i-1]*2+1;
    }
    // cout << h << endl;
    unsigned long long x = 1;
    // cout << (x<<h) << endl;
    for(unsigned long long i = 0; i <= h; i++){
        if((x<<i) & n){
            ans += a[i];
        }
    }
    // cout << (1<<32) << endl;
    cout << ans << endl;
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
