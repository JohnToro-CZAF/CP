#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

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
    ll n; string s;
    cin >> n >> s;
    ll count = 0;
    while(count < n){
        if(s[count] == 'L'){
            count += 2;
            cout << "LR";
        } else if(s[count] == 'U'){
            count +=1;
            cout << "D";
        } else if(s[count] == 'D'){
            count += 1;
            cout << "U";
        }
    }
    cout << endl;    
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

