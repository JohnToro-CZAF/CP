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

ll pow(ll & n, ll & k){
	if(k == 0){
		return n;
	}
	n *= n;
	pow(n, k-1);
}

bool valid(ll a, ll b){

}

void solve(){
	long long a, b;
	scanf("%lld%lld", &a, &b);
	int c = 0;
	for(int i = 0; (1LL << i) / 2 <= b; ++i)
		for(int j = 0; j <= i - 2; ++j) {
			long long x = (1LL << i) - 1 - (1LL << j);
			c += a <= x && x <= b;
		}
	printf("%d\n", c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	solve();

}

