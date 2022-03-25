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

void solve(){
    ll n;
    string s;
    cin >> n >> s;
    ll a[n];
    ll temp = n/2;
    bool chk = true;
    for(ll i = 0; i < n; i++){
        a[i] = s[i] - '0';
        if(a[i] == 0) chk = false;
    }
    if(chk){
        if(n == 2){
            cout << 1 << " " << 2 << " " << 1 << " " << 1 << "\n";
            return;
        } else {
            cout << 1 << " " << 2*temp << " " << 1 << " " << temp << "\n";
            return;
        } 
    }
    for(ll i = 0; i < n - temp; i++){
        if(a[i] == 0){
            cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
            return;
        }
    }
    for(ll i = n - temp; i < n; i++){
        if(a[i] == 0){
            cout << 1 << " " << i+1 << " " << 1 << " " << i << "\n";
            return;
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

