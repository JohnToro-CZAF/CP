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
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    ll curx = 0, cury = 0;
    ll minx = 0, miny = 0, maxx = 0, maxy = 0;
    forn(i, s.length()){
        if(s[i] == 'U'){
            curx--;
        }
        if(s[i] == 'D'){
            curx++;
        }
        if(s[i] == 'L'){
            cury--;
        }
        if(s[i] == 'R'){
            cury++;
        }
        minx = min(minx, curx);
        miny = min(miny, cury);
        maxx = max(maxx, curx);
        maxy = max(maxy, cury);
        if(maxx - minx + 1 > n || maxy - miny + 1 > m){
            break;
        }
        cout << minx << " " << miny << endl;
    }
    cout << 1 + minx << " " << 1 + miny << endl;
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

