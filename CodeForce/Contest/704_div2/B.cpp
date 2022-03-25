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
 
ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}
 
void solve(){
    vector<pair<ll, ll> > v1;
    ll n;
    cin >> n;
    for(ll i = 0; i <n; i++){
        ll ai;
        cin >> ai;
        a[i] = ai;
        v1.push_back(make_pair(ai, i));
    }
    sort(v1.rbegin(), v1.rend());
    ll r = v1[0].s;
    ll l = n;
    ll i = 0;
    while(n != 0){
        if(v1[i].s > r){
            i++;
            continue;
        }
        r = v1[i].s;
        for(ll j = r; j < l; j++){
            cout << a[j] << " ";
        }
        n -= (l-r); 
        l = r;
        i++;
    }
}
 
int main(){
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);
    int c;
    cin >> c;
    while(c--){
        solve();
        cout << "\n";
    }
}