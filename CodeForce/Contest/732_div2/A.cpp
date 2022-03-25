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
    int n;
    cin >> n;
    int a[n];
    int b[n];
    ll suma = 0;
    ll sumb = 0;
    forn(i,n){
        cin >> a[i];
        suma += a[i];
    }
    forn(i,n){
        cin >> b[i];
        sumb += b[i];
    }
    if(suma != sumb){
        cout << -1 << endl;
    } else {
        vector<pair<int, int> > v;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                for(int j = 0; j < n; j++){
                    while(a[j] < b[j] && a[i] > b[i]){
                        cnt++;
                        v.push_back(make_pair(i+1, j+1));
                        a[j]++;
                        a[i]--;
                    }
                }
            }
        }
        cout << cnt << endl;
        forn(i, v.size()){
            cout << v[i].first << " " << v[i].second << endl;
        }
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

