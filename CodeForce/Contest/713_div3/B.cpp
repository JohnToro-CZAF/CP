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
    ll n;
    cin >> n;
    ll m = n*n;
    char a[n][n];
    vector<pair<ll, ll> > v;
    forn(i, n){
        forn(j, n){
            cin >> a[i][j];
            if(a[i][j] == '*'){
                v.push_back(make_pair(i, j));
            }
        }
    }
    int x1,y1,x2,y2;
    if(v[0].second == v[1].second){
        if(v[0].second == n-1){
            y1 = n - 2;
            y2 = n - 2;
        } else {
            y1 = v[0].second + 1;
            y2 = y1;
        }
        x1 = v[0].first;
        x2 = v[1].first;
    } else if (v[0].first == v[1].first){
        if(v[0].first == n-1){
            x1 = n - 2;
            x2 = x1;
        } else {
            x1 = v[0].first + 1;
            x2 = x1;
        }
        y1 = v[0].second;
        y2 = v[1].second;
    } else {
        x1 = v[1].first;
        x2 = v[0].first;
        y1 = v[0].second;
        y2 = v[1].second;
    }
    a[x1][y1] = '*';
    a[x2][y2] = '*';
    forn(i, n){
        forn(j, n){
            cout << a[i][j];
        }
        cout << "\n";
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

