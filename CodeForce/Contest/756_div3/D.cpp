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
    int n;
    cin >> n;
    int a[n+1];
    int b[n+1];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i<=n; i++){
        int x;
        cin >> x;
        b[x] = i;
    }
    bool chk = true;
    vector<int> v;
    for(int i = 1; i <= n; i++){
        // cout << b[i] << " " << b[a[i]] << endl;
        if(b[i] >= b[a[i]]){
            v.push_back(b[i] - b[a[i]]);
        } else {
            chk = false;
            break;
        }
    }
    if(!chk){
        cout << -1 << endl;
    } else {
        for(auto &x: v){
            cout << x << " ";
        }
        cout << "\n";
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

