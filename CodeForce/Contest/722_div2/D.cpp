#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

const int maxn = 1e6+9;
const int maxm = 1e6+1;
ll dp[maxm];
ll mod = 998244353;
bool isPrime[maxn];
vector<int> prime;

void calprime(){
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i < maxn; i++){
        if(isPrime[i]){
            for(int j = i*i; j < maxn; j+=i){
                isPrime[j] = false;
            }
        }
    }
    forn(i, maxn){
        if(isPrime[i]) prime.push_back(i);
    }
}

ll cal(ll n){
    ll ans = 1;
    ll cnt = 0;
    for(int i = 0; prime[i]*prime[i] <= n; i++){
        if(n % prime[i] != 0) continue;
        while(n%prime[i]==0){
            cnt++;
            n /= prime[i];
        }
        ans *= (cnt+1);
        cnt = 0;
    }
    if(n > 1) ans *= 2;
    return ans % mod;
}

ll sum = 0;

void solve(){
    memset(dp, 0, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    sum += dp[0] + dp[1];
    for(ll i = 2; i < maxm; i++){
        dp[i] += sum + cal(i);
        dp[i] %= mod;
        sum += dp[i];
        sum %= mod;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    calprime();
    solve();
    int n;
    cin >> n;
    // cout << cal(18) << endl;
    // cout << prime[2] << endl;
    cout << dp[n] << endl;
}

