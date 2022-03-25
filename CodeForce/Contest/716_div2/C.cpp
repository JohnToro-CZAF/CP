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
    ll product = 1;
    int n;
    cin >> n;
    int cnt = 0;
    vector<int> v;
    if(n == 2 || n==1){
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    for(int i = 1; i <= n-1; i++){
        if(gcd(i, n) == 1){
            v.push_back(i);
            product *= i;
            product %= n;
            cnt++;
        }
    }
    if(product != 1){
        cnt--;
        cout << cnt << endl;
        for(int i = 0; i < v.size()-1; i++){
            cout << v[i] << " ";
        }
    } else {
        cout << cnt << endl;
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

