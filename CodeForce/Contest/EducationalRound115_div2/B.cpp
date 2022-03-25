#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (ll i = 0; i < int(n); i++)
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
    ll a[n][5];
    forn(i, n){
        forn(j, 5){
            ll temp;
            cin >> a[i][j];
        }
    }
    bool chk = false;
    forn(i, 5){
        forn(j, 5){
            if(i!=j){
                bool flag = true;
                ll c = 0;
                ll b = 0;
                forn(z, n){
                    if(a[z][i] == 1) c++;
                    if(a[z][j] == 1) b++;
                }
                ll d[n];
                bool tk = true;
                tk = (c >= n/2 && b >= n/2);
                forn(z, n){
                    d[z] = a[z][i]|a[z][j];
                    if(!d[z]) flag = false;
                }
                if(flag){
                    if(tk) chk = true;
                }
            }
        }
    }
    if(chk){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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

