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
    string s;
    forn(i, n){
        cin >> a[i];
    }
    cin >> s;
    vector<ll> r;
    vector<ll> b;
    forn(i, n){
        if(s[i] == 'B') b.push_back(a[i]);
        if(s[i] == 'R') r.push_back(a[i]);
    }
    bool flag = true;
    sort(b.begin(), b.end());
    sort(r.rbegin(), r.rend());
    forn(i, r.size()){
        if(r[i] > n - i){
            flag = false;
            break;
        }
    }
    forn(i, b.size()){
        if(b[i] < i + 1){
            flag = false;
            break;
        }
    }
    if(flag) {
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

