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
    string s;
    int n;
    char c;
    cin >> n >> c >> s;
    vector<int> v;
    forn(i, n){
        if(s[i] == c){
            v.push_back(i+1);
        }
    }
    bool chk = true;
    forn(i, n){
        if(s[i] != c) chk = false;
    }
    if(chk){
        cout << 0 << endl;
        return;
    }
    bool f = false;
    int index = 0;
    for(int i = 1; i <= n; i++){
        bool flag = true;
        for(int j = i; j <= n; j+=i){
            if(s[j-1] != c){flag = false; break;}
        }
        if(flag){f = true; index = i; break;}
    }
    if(f){
        cout << 1 << endl;
        cout << index << endl;
        return; 
    } else {
        cout << 2 << endl;
        cout << n-1 << " " << n << endl;
        return;
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

