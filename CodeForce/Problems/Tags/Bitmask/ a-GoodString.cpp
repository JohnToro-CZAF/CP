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
    ll a[4][n][n];
    ll b[2][n][n];
    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = 0; k < n; k++){
                if((j+k) % 2 == 0){
                    b[i][j][k] = i;
                } else {
                    b[i][j][k] = abs(i-1);
                }
            }
        }
    }
    for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < n; j++){
            string s;
            cin >> s;
            for(ll k = 0; k < n; k++){
                if(s[k] == '0') a[i][j][k] = 0;
                else a[i][j][k] = 1;
            }
        }
    }
    set<ll> s;
    for(ll i = 0; i < 4; i++){
        for(ll j = 0; j < 4; j++){
            if(i != j){
                s.insert((1<<i) + (1<<j));
            }
        }
    }
    ll ans = inf;
    for(auto x : s){
        ll c[4];
        for(ll i = 0; i < 4; i++){
            if(x & (1 << i)) c[i] = 1;
            else c[i] = 0;
        }
        ll res = 0;
        for(ll i = 0; i < 4; i++){
            for(ll j = 0; j < n; j++){
                for(ll k = 0; k < n; k++){
                    if(b[c[i]][j][k] != a[i][j][k]) res++;
                }
            }
        }
        ans = min(res, ans);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
