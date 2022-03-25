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
    signed long long int n, k;
    cin >> n >> k;
    // cout << n << " " <<  k << endl;
    if(n%2 == 0){
        // cout << n << endl;
        if(k % 4 == 1){
                        // cout << "dis" << endl;
            cout << n - k << endl;
        }
        if(k % 4 == 2){
                        // cout << "dis" << endl;
            cout << n+1 << endl;
        }
        if(k%4 == 3){
                        // cout << "dis" << endl;
            cout << n + k + 1 << endl;
        }
        if(k%4 == 0){
                        // cout << "dis" << endl;
            cout << n << endl;
        }
    }
    if(abs(n%2) == 1){
        // cout << n << endl;
        if(k % 4 == 1){
                        // cout << "dis" << endl;
            cout << n + k << endl;
        }
        if(k % 4 == 2){
                        // cout << "dis" << endl;
            cout << n-1 << endl;
        }
        if(k%4 == 3){
            // ll temp = n - k - 1;
            // cout << "dis" << endl;
            cout << n - k - 1 << endl;
        }
        if(k%4 == 0){
            // cout << "dis1" << endl;
            cout << n << endl;
        }
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

