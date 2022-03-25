#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
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

ll findTheStriclyLessPower(ll base, ll n){
    if(n == 1){
        return 0;
    }
    ll temp = log(n)/log(base);
    if(power(base, temp) == n){
        return temp - 1;
    } else {
        return temp;
    }
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
    int k; 
    cin >> k;
    ll ans = 1;
    ll mod = 1e9+7;
    ll t = (1ll << (k+1)) - 4;
    t %= (mod-1);
    ll x = t % 5;
    for(int i = 1; i <= t/5; i++){
        ans *= 32;
        ans %= mod;
    }
    ans *= (1<<x);
    ans *= 6;
    ans %= mod;
    cout << ans << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

