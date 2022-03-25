#include<cmath>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
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

const int INF = 1e9+1;

void solve(){
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    vector<int> b(n-1);
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n-1){
        cin >> b[i];
    }
    ll bal = 0;
    ll cur = 0;
    ll ans = INF;
    forn(i, n){
        ans = min(ans, cur + cei(c-bal, a[i]));
        ll temp = max(0ll, cei(b[i]-bal ,a[i]));
        cur += temp+1;
        bal += a[i]*temp-b[i];
    }
    cout << ans << "\n";
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

