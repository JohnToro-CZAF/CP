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
    string s;
    cin >> s;
    string t;
    cin >> t;
    ll n = s.length();
    ll ans = 0;
    ll a[27][27];
    forn(i, n){
        forn(j, n){
                ll tempa = s[i] - 'a';
                ll tempb = s[j] - 'a';
                a[tempa][tempb] = abs(i-j);
                a[tempb][tempa] = abs(i-j);
                // cout << tempa << " " << tempb << endl;
        }
    }
    ll m = t.length();
    // cout << "start" << endl;
    forn(i, m-1){
        ll tempa = t[i] -'a';
        ll tempb = t[i+1] - 'a';
        ans += a[tempa][tempb];
        // cout << a[tempa][tempb] << endl;
    }   
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










