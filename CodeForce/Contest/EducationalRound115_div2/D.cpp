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
    vector<pair<ll, ll> > v;
    set<pair<ll, ll> > sp;
    ll sa[n+4], sb[n+4];
    for (ll i = 1; i <= n; ++i)
    {
        sa[i] = 0;
        sb[i] = 0;
    }
    forn(i, n){
        ll x, y;
        cin >> x >> y;
        sp.insert(make_pair(x,y));
        sa[x]++;
        sb[y]++;
    }
    ll difa = 0;
    ll difb = 0;
    // for(auto x : sa1){
    //     difa++;
    // }
    // for(auto x : sb1){
    //     difb++;
    // }
    ll ans = n*(n-1)*(n-2)/6;
    // ll A = 0,B = 0;
    // for(auto x : sa1){
    //     ll temp = sa.count(x);
    //     if(temp >= 3){
    //         A += temp*(temp-1)*(temp-2)/6;
    //     }
    //     if(temp >= 2){
    //         A += temp*(temp-1)*(difa - 1)/2;
    //     }
    // }
    // for(auto x : sb1){
    //     ll temp = sb.count(x);
    //     if(temp >= 3){
    //         B += temp*(temp-1)*(temp-2)/6;
    //     }
    //     if(temp >= 2){
    //         B += temp*(temp-1)*(difb-1)/2;
    //     }
    // }
    ll res = 0;
    for(auto t : sp){
        ll tempa = t.first;
        ll tempb = t.second;
        // cout << "fuck" << endl;
        if(sa[tempa] > 1 && sb[tempb] > 1){
        res += (sa[tempa]-1)*(sb[tempb]-1);}
    }
    // cout << A << " " << B <<endl;
    // cout << res << endl;
    cout << ans - res << endl;
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

