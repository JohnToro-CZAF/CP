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
    int n, k;
    cin >> n >> k;
    vector<int> both;
    vector<int> a;
    vector<int> b;
    forn(i, n){
        int x,y,z;
        cin >> x >> y >> z;
        if(y == z && y == 1){
            both.push_back(x);
        } else if(y == 1 && z == 0){
            a.push_back(x);
        } else if (y == 0 && z == 1){
            b.push_back(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(both.begin(), both.end());
    int toboth = 0;
    int todes = 0;
    ll sum = 0;
    // cout << a.size() << " " <<  b.size() << endl;
    int c = min(a.size(), b.size());
    int d = both.size();
    // cout << c << " " << d << endl;
    while(todes + toboth < k && (todes < c) && toboth < d){
        if(both[toboth] < a[todes] + b[todes]){
            sum += both[toboth];
            toboth++;
        } else {
            sum += a[todes] + b[todes];
            todes++;
        }
            // cout << sum << endl;
    }
    if(todes + toboth == k){
        cout << sum << endl;
    } else {
        if(todes != c || toboth != d){
            if(todes < c){
                while(todes < c && todes+toboth != k){
                    sum += a[todes] + b[todes];
                    todes++;
                }
                if(todes + toboth != k){
                    cout << -1 << endl;
                } else {
                    cout << sum << endl;
                }
            } else {
                while(todes < d && todes+toboth != k){
                    sum += both[toboth];
                    toboth++;
                }
                if(todes + toboth != k){
                    cout << -1 << endl;
                } else {
                    cout << sum << endl;
                }
            }
        } else {
            cout << -1 << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

