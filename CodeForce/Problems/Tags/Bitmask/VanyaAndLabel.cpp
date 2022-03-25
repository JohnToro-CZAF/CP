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
    ll mod = power(10, 9) + 7;
    string s;
    cin >> s;
    ll ans = 1;
    ll z = 0;
    for(ll i = 0; i < s.size(); i++){
        ll temp;
        if( 49 <= s[i] - '0' && s[i] - '0' <= 74){
            temp = s[i] - '0' - 13;
        }
        if(0 <= s[i] - '0' && s[i]-'0' <= 9){
            temp = s[i] - '0';
        }
        if(17 <= s[i] - '0' && s[i] - '0' <= 42){
            temp = s[i] - '0' - 7;
        }
        if(s[i] == '_') temp = 63;
        if(s[i] == '-') temp = 62;
        // cout << temp << endl;
        for(ll j = 0; j <= 5; j++){
            if(!((1<<j) & temp)){
                z++;
            }
        }
    }
    // cout << z << endl;
    while(z--){
        ans *= 3;
        ans = ans%mod;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
