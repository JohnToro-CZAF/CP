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

bool chk(ll n, ll need){
    if(need <= n-2 && need >=0){
        return true;
    }
    return false;
}

void solve(){
    ll n, U, R, D, L;
    cin >> n >> U >> R >> D >> L;
    for(ll i = 0; i < 64; i++){
        ll x, y, z, t;
        x = U; y = R; z = D; t = L;
        if(i & 1){
            x -= 1;
            t -= 1;
        }
        if(i & 2){
            x -= 1;
            y -= 1;
        }
        if(i & 4){
            y -= 1;
            z -= 1;
        }
        if(i & 8){
            z -= 1;
            t -= 1;
        }
        if(chk(n, x) && chk(n, y) && chk(n, z) && chk(n, t)){
            puts("YES");
            return;
        }
    }
    puts("NO");
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
