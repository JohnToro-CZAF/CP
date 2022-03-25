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
    ll i = log(power(10, 20))/log(2);
    ll j = 0;
    int ans = 90;
    // cout << "start" << endl;
    for(ll j = 0; j < i; j++){
        ll temp = 1ll<<j;
        int n1 = n;
        int x = 0, y = 0;
        vector<int> a, b;
        while(temp != 0){
            a.push_back(temp%10);
            temp/=10;
        }
        while(n1 != 0){
            b.push_back(n1%10);
            n1/=10;
        }
        int res = 0;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        forn(i, a.size()){
            // cout << a[i] << " ";
        }
        // cout << "\n";
        forn(i, b.size()){
            // cout << b[i] << " ";
        }
        // cout << "\n";
        int ptra = 0, ptrb = 0;
        while(ptra < a.size() && ptrb < b.size()){
            if(a[ptra] == b[ptrb]){
                ptra++;
                ptrb++;
            } else {
                res++;
                ptrb++;
            }
        }
        res += a.size() - ptra + b.size() - ptrb;
        // cout << (1ll<<j) << " " << res << endl;
        ans = min(res, ans);
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

