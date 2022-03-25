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
    ll x[n], y[n];
    ll j = 0;
    ll k = 0;
    for(ll i = 0; i < 2*n; i++){
        ll t1, t2;
        cin >> t1 >> t2;
        if(t1 == 0){
            y[j] = abs(t2);
            j++;
        } else {
            x[k] = abs(t1);
            k++;
        }
    }
    sort(x, x+n);
    sort(y, y+n);
    double left = 0.0, right = 0.0;
    for(ll i = 0; i < n; i++){
        left += sqrt(x[i]*x[i] + y[i]*y[i]);
    }
    cout.precision(20);
    cout << left << endl;
    // float fuck = 0.0;
    // fuck = sqrt(2)+sqrt(13)+sqrt(16+36)+sqrt(25+9);
    // cout << fuck << endl;
    // fuck = sqrt(37)+sqrt(13)+sqrt(10)+sqrt(16+25);
    // cout << fuck << endl;

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
