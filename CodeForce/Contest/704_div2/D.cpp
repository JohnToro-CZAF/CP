#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
    ll a, b, k;
    cin >> a >> b >> k;
    ll n = a+b;
    string x (n, '0');
    string y (n, '0');
    if(a == 0 && k > 0){
        cout << "NO";
        return;
    }
    if((k == n || k == n-1) && k > 0){
        cout << "NO" << endl;
        return;
    }
    if(b == 1){
        if(k > 0){
            cout << "NO" << endl;
            return;
        }
        if(k == 0){
            cout << "YES" << endl;
            cout << 1;
            for(ll i = 0; i < n-1; i++){
                cout << 0;
            }
            cout << "\n";
            cout << 1;
            for(ll i = 0; i < n-1; i++){
                cout << 0;
            }
        }
        return;
    }
    if(b > 1){
        x[0] = '1';
        y[0] = '1';
        y[n-1] = '1';
        x[n-1-k] = '1';
        ll i = b-2;
        ll j = 0;
        while(i != 0){
            if(n-2 - j- (b-2-i) == n-1-k){
                j++;
                continue;
            }
            x[n-2 -j - (b-2-i)] = '1';
            y[n-2 - j - (b-2-i)] = '1';
            i--;
            // cout << i << endl;
        }
    }
    cout << "YES" << endl;
    for(ll i = 0; i < n; i++){
        cout << x[i];
    }
    cout << "\n";
    for(ll i = 0; i < n; i++){
        cout << y[i];
    }
    cout << "\n";
}

int main(){
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);
    solve();
}
 