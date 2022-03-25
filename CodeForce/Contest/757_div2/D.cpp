#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i,n) for(ll i=0;i<n;++i)

const int maxn = 2e7 + 1;

ll mul[maxn];
ll dp[maxn];
vector<ll> primes;
bool isPrime[maxn];

void precal(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i < maxn; i++){
        if(isPrime[i]){
            for(ll j = (ll)(i*i); j < maxn; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(ll i = 0; i < maxn; i++){
        if(isPrime[i]) primes.push_back(i);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    precal();
    ll n;
    cin >> n;
    ll a[n];
    forn(i, n){
        cin >> a[i];
        mul[a[i]]++;
    }
    for (auto p : primes)
    {
        for (int i = (maxn - 1) / p; i > 0; i--)
        {
            mul[i] += mul[p * i];
        }
    }
    ll ans = 0;
    for(ll i = maxn-1; i > 0; i--){
        dp[i] = i*mul[i];
        for(auto p : primes){
            if(p*i >= maxn) break;
            else dp[i] = max(dp[i], dp[i*p]+(mul[i]-mul[i*p])*i);
        }
        ans = max(ans, dp[i]+n-mul[i]);
    }
    cout << ans << endl;
    return 0;
}

