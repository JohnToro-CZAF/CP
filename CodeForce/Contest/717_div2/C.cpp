#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

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
    ll sum = 0;
    forn(i, n){
        b[i] = 0;
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 2 != 0){
        cout << 0 << endl;
        return;
    }
    sum /= 2;
    vector<bool> possible(sum+1);
    possible[0] = 1;
    forn(i, n){
        for(int j = sum - a[i]; j>=0; j--){
            if(possible[j]){
                possible[j+a[i]] = true;
            }
        }
    }
    if(possible[sum]){
        while(true){
            forn(i, n){
                if(a[i]%2 != 0){
                    cout << 1 << endl;
                    cout << i+1 << endl;
                    return;
                } 
            }
            forn(i,n){
                a[i]/=2;
            }
        }
    } else {
        cout << 0 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

