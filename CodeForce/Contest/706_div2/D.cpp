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
    ll left_incre[n];
    ll right_incre[n];
    ll left_decre[n];
    ll right_decre[n];
    memset(left_decre, 1, sizeof(left_decre));
    memset(left_incre, 1, sizeof(left_incre));
    memset(right_decre, 1, sizeof(right_decre));
    memset(right_incre, 1, sizeof(right_incre));
    for(ll i =0 ; i < n-1; i++){
         if(a[i] > a[i+1]){
            left_incre[i+1] = left_incre[i] + 1;
         }
         if(a[i] < a[i+1]){
            left_decre[i+1] = left_decre[i] + 1;
         }
    }
    for(ll i = n-2 ; i >= 0; i--){
         if(a[i] > a[i+1]){
            right_decre[i] = right_decre[i+1] +1;
         }
         if(a[i] < a[i+1]){
            right_incre[i] = right_incre[i+1] + 1;
         }
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
