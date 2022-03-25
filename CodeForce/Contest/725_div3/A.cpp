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

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

ll lcm(ll x, ll y){
    return x*y/gcd(x, y);
}

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    ll m = inf, M = 0;
    forn(i, n){
        cin >> a[i];
        m = min(m, a[i]);
        M = max(M, a[i]);
    }
    ll ans = 0;
    ll i1, i2;
    forn(i, n){
        if(m == a[i]){
            i1 = i+1;
            break;
        }
    }
    forn(i, n){
        if(M == a[i]){
            i2 = i+1;
            break;
        }
    }
    ans = min(max(i1, i2), max(n-i1+1, n-i2+1));
    ans = min(ans, i1 + n - i2+1);
    ans = min(ans, i2 + n - i1+1);
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

