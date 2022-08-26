#include<string.h>
#include<vector>
#include<iostream>
#include<limits.h>
#include<math.h>
#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<int> primes;

void precal(int limit){
    int is_prime[limit+1];
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i <= limit; i++){
        if(is_prime[i]){
            for(int j = i*i; j <= limit; j+=i){
                is_prime[j] = 0;
            }
        }
    }
    for(int i = 0; i <= limit; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l, r;
    cin >> l >> r;
    ll ans = 1;
    ll mod = 1e9+7;
    int limit = sqrt(r)+1;
    precal(limit);
    int is_prime[r - l + 1];
    memset(is_prime, 1, sizeof(is_prime));
    for(int i = 0; i < primes.size(); i++){
        int low;
        if(l <= primes[i]){
            low = primes[i]*2;
        } else {
            low = floor(l/primes[i])*primes[i];
            if(low < l) low += primes[i];
        }
        for(int j = low; j <= r; j+=primes[i]){
            is_prime[j-l] = 0;
        }
    }
    for(int i = 0; i < r - l +1; i++){
        if(is_prime[i]){
            ans *= (i+l);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0; 
}

