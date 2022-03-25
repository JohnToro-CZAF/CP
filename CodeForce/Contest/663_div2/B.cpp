#include<bits/stdc++.h>
#include<limits.h>

using namespace std;
using ll = long long;

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
    ll n, m;
    cin >> n >> m;
    vector< string > s;
    if(n == m && n == 1){
        cout << 0 << endl;
        return;
    }
    for(ll i = 0; i < n; i++){
        string t;
        cin >> t;
        s.push_back(t);
    }
    ll ans = 0;
    for(ll i = 0; i < m-1; i++){
        if(s[n-1][i] == 'D'){
            ans++;
        }
    }
    for(ll i = 0; i < n-1; i++){
        if(s[i][m-1] == 'R'){
            ans++;
        }
    }
    cout << ans << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
