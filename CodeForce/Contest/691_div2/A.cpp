#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
typedef long long ll;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll a[template_size];
ll b[template_size];
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
    ll n;
    cin >> n;
    string s, t;
    cout << s << t;
    ll red = 0, blue = 0, draw = 0;
    for(ll i = 0; i < n; i++){
        if(s[i] - '0' > t[i] - '0'){
            red++;
        }
        if(t[i] - '0' > s[i] - '0'){
            blue++;
        }
        if(t[i] - '0' == s[i] - '0'){
            draw++;
        }
    }
    if(red == blue){
        cout << "EQUAL" << endl;
    }
    if(blue < red){
        cout << "RED" << endl;
    }
    if(red > blue){
        cout << "BLUE" << endl;
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
