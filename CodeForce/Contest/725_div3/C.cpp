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

int lowerIndex(int arr[], int n, int x, int bound)
{
    int l = 0, h = bound-1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] >= x)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
 
int upperIndex(int arr[], int n, int y, int bound)
{
    int l = 0, h = bound-1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (arr[mid] <= y)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
 
// function to count elements within given range

int countInRange(int arr[], int n, int x, int y, int bound)
{
    // initialize result
    int count = 0;
    count = upperIndex(arr, n, y, bound) - lowerIndex(arr, n, x, bound) + 1;
    return count;
}
void solve(){
    int n, l, r;
    cin >> n >> l >> r;
    int a[n];
    forn(i, n){
        cin >> a[i];
    }
    sort(a, a+n);
    ll ans = 0;
    forn(i, n){
        ans += countInRange(a, n, l - a[i], r - a[i], i);
    }
    cout << ans << endl;
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

