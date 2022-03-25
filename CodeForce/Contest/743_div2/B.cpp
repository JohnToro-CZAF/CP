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
int binarySearchCount(int arr[], int n, int key)
{
    int left = 0, right = n;
 
    int mid;
    while (left < right) {
        mid = (right + left) >> 1;
 
        // Check if key is present in array
        if (arr[mid] == key) {
           
            // If duplicates are present it returns
            // the position of last element
            while (mid + 1 < n && arr[mid + 1] == key)
                mid++;
            break;
        }
 
        // If key is smaller, ignore right half
        else if (arr[mid] > key)
            right = mid;
 
        // If key is greater, ignore left half
        else
            left = mid + 1;
    }
 
    // If key is not found
    // in array then it will be
    // before mid
    while (mid > -1 && arr[mid] > key)
        mid--;
 
    // Return mid + 1 because of 0-based indexing
    // of array
    return mid + 1;
}

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    int c[n], m = 0;
    int d[2*n+49];
    forn(i, n){
        cin >> a[i];
    }
    forn(i, n){
        cin >> b[i];
        m = max(m, b[i]);
        c[i] = m;
    }
    forn(i, n){

    }
    // cout << "\n";
    int ans = 1000000;
    forn(i, n){
        ans = min(ans, i + binarySearchCount(c, n, a[i]));
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

