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

void solve(){
    int n;
    cin >> n;
    int c = 28;
    vector<vector<int> > prefix(28, vector<int>(n+1));
    int a[n];
    set<int> s;
    forn(i, n){
        cin >> a[i];
        s.insert(a[i]);
    }
    prefix[a[0]][0] = 1;
    for(auto &x : s){
        for(int i = 0; i < n; i++){
            prefix[x][i+1] = prefix[x][i] + (a[i]==x);
        }
    }
    int ans = 0;
    for(int i = 1; i <= 26; i++){
        // cout << i << " " << prefix[i][n] - prefix[i][0] << endl;
        ans = max(ans, prefix[i][n] - prefix[i][0]);
    }
    // cout << "temp " << ans << endl;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int cntin = 0;
            int cntout = 0;
            for(int k = 1; k <= 26; k++){
                cntin = max(cntin, prefix[k][j+1] - prefix[k][i]);
                cntout = max(2*min(prefix[k][i] - prefix[k][0], prefix[k][n] - prefix[k][j+1]), cntout);
            }
            ans = max(ans, cntout+cntin);
        }
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

