#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

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

int q(ll i){
    ll t;
    cout << "? " << i << endl;
    cout.flush();
    cin >> t;
    return t;
}

void solve(){
    ll n;
    cin >> n;
    if(n == 1){
        cout << "! "<< 1 << endl;
        cout.flush();
        return;
    }
    ll l = 1, r = n;
    ll res;
    while(l != r){
        ll mid = (r+l)/2;
        ll t1 = q(mid);
        ll t2 = q(mid+1);
        if(t1 < t2){
            r = mid;
        } else {
            l = mid + 1;
        }
        // cout << l <<" " << r << endl;
        res = r;
    }
    cout << "! " << res << endl;
    cout.flush();
}

int main(){
    solve();
}