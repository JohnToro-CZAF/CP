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

void calc(ll l, ll r, ll k){
    if(l == r){
        cout << "! " << l << endl; 
        return;
    }
    ll m = (l+r)/2;
    cout << "? " << l << " " << m << endl;
    cout.flush();
    ll sum;
    cin >> sum;
    if((m-l+1 - sum) >= k){
        calc(l, m, k);
    } else {
        calc(m+1, r, k - (m-l+1) + sum);
    }
}

void solve(){
    ll n, t, k;
    cin >> n >> t >> k;
    calc(1, n, k);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

