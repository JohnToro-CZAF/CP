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
    ll m = 0;
    forn(i, n){
        cin >> a[i];
    }
    // cout << "start" << endl;
    forn(i, n){
        ll e = 0;
        forn(j ,n){
            if(a[j] == a[i]) e++;
        }
        if(e >= n/2){
            cout << -1 << endl;
            return;
        }
        multiset<ll> s;
        set<ll> s1;
        forn(j, n){
            if(a[j] > a[i]){
                ll temp = a[j] - a[i];
                for(ll t = 1; t <= sqrt(temp); t++){
                    if(t*t == temp){s.insert(t); s1.insert(t); continue;}
                    if((a[j] - a[i]) % t == 0){s.insert(t); s1.insert(t); s.insert(temp/t); s1.insert(temp/t);}
                }
            }
        }
        for(auto x : s1){
            // cout << x << " " << e << " " << s.count(x) << endl;
            if(e + s.count(x) >= n/2){
                m = max(m, x);
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

