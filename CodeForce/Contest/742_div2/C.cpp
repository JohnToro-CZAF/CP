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

ll cal(ll n){
    if(n < 10){
        return n+1;
    } else {
        return 18 - n;
    }

}

void solve(){
    string s, s1, s2, s3;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {s1 += s[i];}
        else if (i % 2 == 1) {s2 += s[i];}
    }
    if (s2.empty()) {
        cout << stoi(s1) - 1 << endl; return;
    }
    cout << (stoi(s1) + 1) * (stoi(s2) + 1) - 2 << endl;
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

