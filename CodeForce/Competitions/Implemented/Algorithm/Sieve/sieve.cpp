#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;

const int maxn = 2e5+9;
const int maxp = sqrt(maxn) + 1;

vector<int> primes;
vector<int> post_primes;
// precal primes from 0 -> sqrt(n)
void precal(){
    int is_prime[maxp];
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = 0;
    for(int i = 2; i < maxp; i++){
        if(is_prime[i]){
            for(int j = i*i; j < maxp; j+=i){
                is_prime[j] = 0;
            }
        }
    }
    for(int i = 0; i < maxp; i++){
        if(is_prime[i]){
            primes.push_back(i);
            post_primes.push_back(i);
        }
    }
}

void cal(){
    int low = maxp;
    int high = maxp*2;
    precal();
    while(low < maxn){
        if(high >= maxn){
            high = maxn;
        }
        int is_prime[maxp+1];
        memset(is_prime, 1, sizeof(is_prime));
        for(int i = 0; i < primes.size(); i++){
            int first = floor(low/primes[i])*primes[i];
            if(first < low) first += primes[i];
            for(int j = first; j < high; j+=primes[i]){
                is_prime[j-low] = 0;
            }
        }
        for(int i = 0; i < maxp; i++){
            if(is_prime[i]){
                post_primes.push_back(i+low);
            }
        }
        low += maxp;
        high += maxp;
    }
}

int main(){
    cal();
    for(int i = 0; i < post_primes.size(); i++){
        cout << post_primes[i] << " ";
    }
    return 0;
}