#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

int cei(int x, int y){
    int t = (x+y-1)/y;
    return t;
}


void solve(){
    int n, h;
    cin >> n >> h;
    int a[n];
    forn(i, n){
        cin >> a[i];
    }
    int b[n];
    memset(b, 0, sizeof(b));
    for(int i = 1; i < n; i++){
        b[i] = a[i] - a[i-1];
        b[i];
    }
    b[0] = 0;
    sort(b, b+n);
    int sum = 0;
    int ans = 1e9+7;
    forn(i, n){
        sum += b[i];
        int t = cei(h-sum, n-i+1);
        int temp = max(t, b[i]);
        ans = min(ans, temp);
        cout << i+1 << " " << t << endl;
    }
    // cout << "di" << endl;
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

