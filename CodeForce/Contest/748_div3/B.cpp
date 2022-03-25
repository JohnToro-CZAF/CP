#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
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

int count_digit(ll number) {
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}

void solve(){
    ll n;
    cin >> n; 
    ll k = count_digit(n);
    ll tempn = n;
    ll a[k];
    forn(i, k){
        a[k-1-i] = tempn % 10;
        tempn /= 10;
    }
    forn(i ,k){
        // cout << a[i] << " ";
    }
    ll m = inf;
    for(ll i = 1; i < k; i++){
        if(a[i] == 0){
            for(ll j = i-1; j >= 0; j--){
                if(a[j] == 5 || a[j] == 0){
                    m = min(i - j - 1 + k - i - 1, m);
                }
            }
        }
        if(a[i] == 5){
            for(ll j = i-1; j >= 0; j--){
                if(a[j] == 2 || a[j] == 7){
                    m = min(i - j - 1 + k - i - 1, m);
                }
            }
        }
    }
    cout << m << endl;
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

