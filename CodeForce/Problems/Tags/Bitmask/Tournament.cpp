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
    ll won[n], num[n];
    memset(won, 0, sizeof(won));
    memset(num, 0, sizeof(num));
    for(ll i = 0; i < n*(n-1)/2-1; i++){
        ll x, y;
        cin >> x >> y;
        won[x-1]++;
        num[x-1]++;
        num[y-1]++;
    }
    ll a[2];
    memset(a, 0, sizeof(a));
    ll j = 0;
    for(ll i = 0; i < n; i++){
        if(num[i] != n-1){
            a[j] = i;
            j++;
        }
    }
    // cout << a[0] << " " << a[1] << endl;
    if(won[a[0]] >= won[a[1]]){
        cout << a[0] + 1<< " " << a[1] +1 << endl;
    } else {
        cout << a[1] + 1<< " " << a[0] + 1<< endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
