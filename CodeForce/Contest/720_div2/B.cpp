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

bool checkPrime(ll n){
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

ll nextPrime(ll n){
    ll ans = n+1;
    while(!checkPrime(ans)){
        // cout << ans << "f" << endl;
        ans++;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll temp = a[0];
    ll index = 0;
    for(ll i = 0; i < n; i++){
        if(a[i] <= temp){
            temp = a[i];
            index = i;
        }
    }
    cout << n-1 << endl;
    for(ll i = 0; i < n; i++){
        if(i == index) continue;
        else {
            cout << index+1 << " " << i+1 << " " << a[index] << " " << abs(i-index) + a[index] << endl;
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

