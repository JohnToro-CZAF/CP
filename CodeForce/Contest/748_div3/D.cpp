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
    ll n; 
    cin >> n;
    ll a[n];
    forn(i, n){
        cin >> a[i];
    }
    multiset<ll> s;
    forn(i, n){
        forn(j, n){
            if(i != j){
                s.insert(abs(a[i]-a[j]));
            }
        }
    }
    set<ll> s1;
    for(auto x : s){
        for(ll i = 1; i <= sqrt(abs(x)); i++){
            if(x%i == 0){
                s1.insert(i);
                s1.insert(x/i);
            }
        }
    }
    bool flag = false;
    ll m = 0;
    for(auto x : s1){
        bool flag1 = true;
        for(auto y : s){
            if(y % x != 0) flag1 = false;
        }
        if(flag1){m = max(m, x); flag = flag1;}
        else continue; 
    }
    if(flag){cout << m << endl;}
    else cout << -1 << endl;
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

