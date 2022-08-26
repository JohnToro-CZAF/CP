#include<vector>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

const int maxn = 2e5+9;
vector<int> primes;
int is_prime[maxn+1];
void precal(){
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i = 2; i <= maxn; i++){
        if(is_prime[i]){
            for(long long j = (long long)i*i; j <= maxn; j+=i){
                is_prime[j] = 0;
            }
        }
    }
    for(int i = 0; i <= maxn; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}

int main(){
    precal();
    int n;
    cin >> n;
    if(is_prime[n]) {
        cout << n << " " << 1 << endl;
        return 0;
    }
    int m = sqrt(n)+1;
    int cnt[m+1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < primes.size(); i++){
        if(primes[i]*primes[i] > n) break;
        if(n % primes[i] == 0){
            while(n % primes[i] == 0){
                cnt[primes[i]]++;
                n /= primes[i];
            }
        }
    }
    for(int i = 0; i <= m; i++){
        if(cnt[i] > 0){
            cout << i << " " << cnt[i] << endl;
        }
    }

    return 0;
}

