#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
struct tuple {ll x; ll y; ll z;};
const int mod = 1e9+7;
ll inf = LONG_MAX;

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

ll power(ll base, ll powerRaised)
{
    base %= mod;
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}

void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = power(n, k);
    ans %= mod;
    cout << ans << endl;
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

