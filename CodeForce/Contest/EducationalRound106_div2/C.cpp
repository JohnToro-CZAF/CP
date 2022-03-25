#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_LONG_MAX;

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
    ll n;
    cin >> n;
    ll c[n];
    ll sum[n];
    ll sum0 = 0;
    ll sum1 = 0;
    ll a[n];
    ll min0 = inf;
    ll min1 = inf;
    forn(i, n){
        cin >> c[i];
        if(i%2 == 0){
            sum0 += c[i];
            sum[i] = sum0;
            min0 = min(min0, c[i]);
            a[i] = min0;
        } else{
            sum1 += c[i];
            sum[i] = sum1;
            min1 = min(min1, c[i]);
            a[i] = min1;
        }
    }   
    ll res = inf;
    for(ll k = 1; k <= n -1 ;k++){
        if(k % 2 == 0){
            res = min(res, sum[k] + (n - k/2 - 1)*a[k] + sum[k-1] + (n - k/2)*a[k-1]);
        } else {
            ll temp = (k+1)/2;
            res = min(res, sum[k-1] + (n - temp)*a[k-1] + sum[k] + (n - temp)*a[k]);
        }
    }
    cout << res << endl;
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

