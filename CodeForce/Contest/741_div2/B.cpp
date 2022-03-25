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
    ll k;
    string s;
    cin >> k >> s;
    ll a[k];
    for(ll i = 0; i < k; i++){
        a[i] = s[i] - '0';
    }
    if( k == 1){
        // cout << "git";
        cout << 1 << "\n";
        cout << s[0] - '0' << "\n";
        return;
    }
    multiset<ll> number;
    ll number1[11];
    ll number2[11];
    ll number3[11];
    for(ll i = 1; i < 11; i++){
        number1[i] = 0;
    }
    for(ll i = 0; i < k; i++){
        number1[a[i]]++;
    }
    number.insert(1);
    number.insert(4);
    number.insert(6);
    number.insert(8);
    number.insert(9);
    for(ll i = 0; i < k; i++){
        // cout << number.count(a[i]) << "\n";
        if(number.count(a[i]) >= 1){
            cout << 1 <<"\n";
            cout << a[i] << "\n";
            return;
        }
    }
    for(ll i = 2; i <= 10; i ++){
        // cout << number1[i] << "this is shit" << "\n";
        if(number1[i] >= 2 && number1[i] <= 51){
            cout << 2 << "\n";
            cout << i*10+i << "\n";
            // cout << "fuck";
            return;
        }
    }
    for(ll i = 1; i < 11; i++){
        number2[i] = 0;
        number3[i] = 0;
    }
    for(ll i = k-1; i >= 0; i--){
        number2[a[i]]++;
        if((number2[5] > 0 || number2[2] > 0) && i > 0){
            cout << 2 << "\n";
            // cout << "fuck*";
            if(number2[5] > 0){
                cout << a[0]*10 + 5 << "\n";
                // cout << "fuck1" << "\n";
                return;
            }
            if(number2[2] > 0){
                cout << a[0]*10 + 2 << "\n";
                // cout << "fuck2" << "\n";
                return;
            }
        }
        if(number2[7] > 0 && i > 0){
            for(ll j = i - 1; j >= 0; j--){
                number3[a[j]]++;
                if(number3[2] > 0){
                    cout << 2 << "\n";
                    cout << 27 << "\n";
                    return;
                }
                if(number3[5] > 0){
                    cout << 2 << "\n";
                    cout << 57 << "\n";
                    return;
                }
            }
        }
    }
    cout << 2 <<"\n";
    cout << 27 << "\n";
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

