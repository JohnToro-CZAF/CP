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
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i <= cei(n-1, 2); i++){
        for(int j = 0; j <= cei(m-1, 2); j++){
            int t = (a[i][j] + a[n-1-i][j] + a[i][m-1-j]+a[n-1-i][m-1-j])/4;
            a[i][j] = t;
            a[n-1-i][j] = t;
            a[i][m-1-j] = t;
            a[n-1-i][m-1-j] = t;
            ans += abs(a[i][j] - t);
            ans += abs(a[n-1-i][j] - t);
            ans += abs(a[i][m-1-j] - t);
            ans += abs(a[n-1-i][m-1-j] - t);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
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

