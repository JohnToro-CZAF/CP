#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (ll i = 0; i < ll(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

const int maxn = 2e5+9;
vector<vector<ll> > edge(maxn);
vector<pair<ll, ll> > range(maxn); 
ll dp[maxn][2];
// ll sum = 0;
void dfs(ll s, ll prev){
    dp[s][0] = dp[s][1] = 0;
    for(auto x : edge[s]){
        if(x == prev) continue;
        dfs(x, s);
        dp[s][0] += max(dp[x][0] + abs(range[s].first - range[x].first), dp[x][1] + abs(range[s].first - range[x].second));
        dp[s][1] += max(dp[x][0] + abs(range[s].second - range[x].first), dp[x][1] + abs(range[s].second - range[x].second));
    }
}

void solve(){
    ll n;
    cin >> n;
    forn(i, n){
        edge[i].clear();
    }
    range.clear();
    range.assign(n, make_pair(0, 0));
    forn(i, n){
        ll li, ri;
        cin >> range[i].first >> range[i].second;
    }
    forn(i, n-1){
        ll x, y;
        cin >> x >> y;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(0, -1);
    ll ans = max(dp[0][1], dp[0][0]);
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

