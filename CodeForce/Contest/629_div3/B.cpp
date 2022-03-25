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
    int k;
    cin >> k;
    string s;
    cin >> s;
    int map[11];
    forn(i, 9){
        int c;
        cin >> c;
        map[i+1] = c;
    }
    bool find = false;
    int index;
    for(int i = 0; i < k; i++){
        if(map[s[i]-'0'] > s[i] - '0'){
            index = i;
            find = true;
            break;
        }
    }
    if(find){
        for(int i = index; i < k; i++){
            if(map[s[i]-'0'] >= s[i] - '0'){
                s[i] = map[s[i]-'0'] + '0';
            } else {
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < k; i++){
        cout << s[i]; 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

