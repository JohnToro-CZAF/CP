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
   int a,b;
   cin >> a >> b;
   long long sum1 = 0;
   long long sum2 = 0;
   int ka = a/3;
   int kb = b/3;
   if(b%3 == 2){
        if(a%3 == 1){
            sum1 = kb*a + 2*ka + 1;
        } else if(a%3 == 2){
            sum1 = kb*a + 2*ka + 2;
        } else{
            sum1 = kb*a + 2*ka;
        }
   } else if(b%3 == 1){
        sum1 = kb*a + cei(a, 3);
   } else {
        sum1 = kb*a;
   }
   cout << sum1 << endl;
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

