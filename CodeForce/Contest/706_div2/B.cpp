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
	ll n, k;
    cin >> n >> k;
    bool chk = true;
    vector<ll> v;
    multiset<ll> s;
    ll m = 0;
    ll u = 0;
    for(ll i = 0; i < n; i++){
        ll t;
        cin >> t;
        v.push_back(t);
        if(s.count(t) == 0) u++;
        s.insert(t);
        m = max(m, t);
    }
    sort(v.begin(), v.end());
    ll need;
    for(ll i = 0; i < n; i++){
        if(i != v[i]){
            chk = false;
            need = i;
            break;
        }
    }
    // cout << u << "cac" << endl;
    if(chk){
        cout << n+k << endl;
    } else {
        ll temp = need + m;
        ll x = (k > 0) ? 1 : 0;
        if(s.count(cei(temp, 2)) == 0){
            cout << u+x << endl;
        } else {
            cout << u << endl;
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
