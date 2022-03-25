#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

bool solve(ll a, ll b, ll x){
    // cout << a << " " << b << endl;
    if(a == x || b == x){
        return true;
    }
    if(a == 0){
        if(b == x) return true;
        else return false;
    }
    if((b - x) % a == 0 && b > x){
        return true;
    }
    ll k = b/a;
    return solve(min(b-k*a, a), max(b-k*a, a), x);
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        ll a,b,x;
        cin >> a >> b >> x;
        bool f = solve(min(a,b), max(a,b), x);
        if(f){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

