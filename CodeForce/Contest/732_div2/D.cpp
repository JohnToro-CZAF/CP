#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

const int N = 2e5 + 8;
const int MOD = 998244353;
ll fact[N], inv[N], invfact[N]; 
ll mul(int x, int y) {
    return (1LL * x * y) % MOD;
}
void factInverse() {
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for (long long i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD); 
        invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
    }
}
ll nCr(ll n, ll r) {
    if (r > n)
        return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += '$';
    vector<int> v;
    int cnt = 0;
    int cnt1 = 0;
    int temp = 1;
    int i = 0;
    while(i != n){
        if(s[i] == '0'){cnt++; i++; continue;}
        while(s[i] == s[i+1] && s[i] == '1'){
            temp++;
            i++;
        }
        cnt1 += temp/2;
        temp = 1;
        i++;
    }
    // cout << cnt << " " << cnt1 << endl;
    ll tempn = cnt+cnt1;
    ll ans = nCr(tempn, cnt1);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    factInverse();
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

