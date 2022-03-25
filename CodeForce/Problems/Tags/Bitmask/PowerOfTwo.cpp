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
    ll n,k;
    cin >> n >> k;
    ll h = log(n)/log(2) + 1;
    ll p = 0;
    queue<ll> s;
    for(ll i = h; i >=0; i--){
        if(1<<i & n){
            p++;
            s.push(i);
        }
    }
    vector<ll> v;
    // cout << p << " " << k << endl;
    if(p <= k && k<= n){
        cout << "YES" << endl;
        while(p != k){
            // cout << "cac";
            ll temp = s.front();
            // v.push_back(temp);
            if(temp > 0){
                s.pop();
                // cout << temp - 1 << endl;
                s.push(temp-1);
                s.push(temp-1);
                p++;
                // cout << "dit";
            } else {
                s.push(temp);
                s.pop();
            }
        }
        while(!s.empty()){
            ll x = s.front();
            cout << power(2, x) << " ";
            s.pop();
        }
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve(); 
}

