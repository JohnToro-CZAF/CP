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
    ll k;
    cin >> n >> k;
    ll a[k];
    ll sum[k];
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    sort(a, a+k);
    if(k== 1) {return; cout << 1 << endl;}
    // cout << "l" << endl;
    ll temp = 0;
    for(ll i = k-1; i >= 0; i--){
        // cout << n - a[i] << " ";
        temp += n - a[i];
        // cout << "duoi" << endl;
        sum[i] = temp; 
        // cout << sum[i] << " ";
    }
    // ll sum1[n];
    // temp = 0;
    // for(ll i = k-1; i >= 0; i--){
    //     // cout << n - a[i] << " ";
    //     temp += sum[i];
    //     sum1[i] = temp; 
    //     cout << sum1[i] << " ";
    // }
    // cout << "\n";
    ll t = 0;
    ll sum1 = 0;
    // while(t < k && sum[k-1-t] < a[k-1-t]){
    //     t++;
    // }
    while(t < k && sum1 < a[k-1-t]){
        sum1 += sum[k - 1 - t];
        t++;
    }
    cout << t << endl;
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

