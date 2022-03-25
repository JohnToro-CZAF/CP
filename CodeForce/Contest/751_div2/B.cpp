#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

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

const int maxn = 1e9 + 13;

// bool chk(int a[], int b[], int n){
//     bool f = true;
//     for(int i = 0; i < n; i++){
//         if(a[i] != b[i]) f = false;
//         break;
//     }
//     return f;
// }

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int b[n+3][n];
    for(int i = 0; i < n; i++){
        b[0][i] = a[i];
    }
    for(int i = 0; i <= n-1; i++){
        map<int, int> m;
        for(int j = 0; j < n; j++){
            m[b[i][j]]++;
            // cout << m[b[i][j]] <<" ";
        }
        for(int j = 0; j < n; j++){
            b[i+1][j] = m[b[i][j]];
        }
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        cout << b[min(n, y)][x-1] << endl;
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

