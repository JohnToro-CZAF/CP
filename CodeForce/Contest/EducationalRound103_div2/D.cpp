#include<bits/stdc++.h>
#include<limits.h>
 
#define f first
#define s second
 
using namespace std;
using ll = long long;
 
ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v; 
ll a[template_size];
ll b[template_size];
ll c[template_size];
ll d[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}
 
void solve(){
    ll n;
    string s;
    cin >> n;
    cin >> s;
    for(ll i = 0; i < n; i++){
        if(s[i] == 'L') d[i] = 0;
        else d[i] = 1;
        a[i] = 1;
    }
    a[n] = 1;

    vector<ll> to_left(n+1);
    vector<ll> to_right(n+1);
    to_left[0] = 0;
    to_left[1] = (d[0] == 0) ? 1 : 0;
    to_right[n] = 0;
    to_right[n-1] = (d[n-1] == 1) ? 1 : 0;
    for(ll i = 2; i < n+1; i++){
        if(d[i-1] == 0 && d[i-2] == 1 ){
            to_left[i] = to_left[i-2] + 2;
            continue;
        }
        if(d[i-1] == 0 && d[i-2] != 1){
            to_left[i] = 1;
            continue;
        }
        if(d[i-1] != 0){
            to_left[i] = 0;
            continue;
        }
    }
    for(ll i = n-2; i >= 0; i--){
        if(d[i] == 1 && d[i+1] == 0){
            to_right[i] = to_right[i+2] + 2;
            continue;
        }
        if(d[i] == 1 && d[i+1] != 0){
            to_right[i] = 1;
            continue;
        }
        if(d[i+1] != 1){
            to_right[i] = 0;
            continue;
        }
    }
    for(ll i = 0; i < n+1; i++){
        a[i] += to_right[i] + to_left[i];
        // cout << to_left[i] << " " << to_right[i] << endl;
    }
    for(ll i = 0; i < n+1; i++){
        cout << a[i] << " ";   
    }
    cout << "\n";
    // cout << to_right[3] << endl;
    // cout << d[4] << endl;
}
 
int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}