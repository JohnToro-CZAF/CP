#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll ans = 1000000003;
vector<vector<ll> > enew(300000);
bool chk = false;

void dfs(ll s, ll v1[], ll d, ll res){
    // cout << s+1 << " " << res << " "  << d << endl;
    if(d == 4){
        chk = true;
        ans = min(ans, res);
        return;
    }
    if(enew[s].size() == 0){
        return;
    }
    for(ll i = 0; i < enew[s].size(); i++){
        dfs(enew[s][i], v1, d+1, res + v1[enew[s][i]]);
    }
}

void solve(){
    ll n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    ll x1 = n1;
    ll x2 = n1+n2;
    ll x3 = n1+n2+n3;
    ll x4 = n1+n2+n3+n4;
    vector<pair<ll, pair<ll, ll> > > v;
    for(ll i = 0; i < x4; i++){
        ll ai;
        cin >> ai;
        pair<ll, pair<ll, ll> > p = make_pair(ai, make_pair(i, 0LL));
        v.push_back(p);
    }
    ll y[x4];
    sort(v.begin(), v.begin()+x1);
    sort(v.begin()+x1, v.begin()+x2);
    sort(v.begin()+x2, v.begin()+x3);
    sort(v.begin()+x3, v.begin()+x4);
    for(ll i = 0; i < x4; i++){
        v[i].second.second = i;
        y[v[i].second.first] = i;
    }
    ll b1,b2,b3;
    ll z[x4][x4];
    for(int i = 0; i <x4; i++){
        for(ll j = 0; j < x4; j++){
            z[i][j] = 0;
        }
    }
    for(ll i = 0; i < x1; i++){
        for(ll j = x1; j < x2; j++){
            z[i][j] = 1;
        }
    }
    for(ll i = x1; i < x2; i++){
        for(ll j = x2; j < x3; j++){
            z[i][j] = 1;
        }
    }
    for(ll i = x2; i < x3; i++){
        for(ll j = x3; j < x4; j++){
            z[i][j] = 1;
        }
    }
    vector<ll> e[x4];
    cin >> b1;
    for(ll i = 0; i < b1; i++){
        ll t1, t2;
        cin >> t1 >> t2;
        z[t1-1][t2-1+x1] = 0; 
    }
    cin >> b2;
    for(ll i = 0; i < b2; i++){
        ll t1, t2;
        cin >> t1 >> t2;
        z[t1-1+x1][t2-1+x2] = 0; 
    }
    cin >> b3;
    for(ll i = 0; i < b3; i++){
        ll t1, t2;
        cin >> t1 >> t2;
        z[t1-1+x2][t2-1+x3] = 0;
    }
    for(ll i = 0; i < x4; i++){
        for(ll j = 0; j < x4; j++){
            if(z[i][j] == 1){
                e[i].push_back(j);
            }
        }
    }
    for(ll i = 0; i < x4; i++){
        for(auto x : e[i]){
            enew[y[i]].push_back(y[x]);
        }
    }
    for(ll i = 0; i < x4; i++){
        sort(enew[i].begin(), enew[i].end());
    
    }
    ll v1[x4];
    for(ll i = 0; i < x4; i++){
        v1[i] = v[i].first;
    }
    for(ll i = 0; i < x1; i++){
        dfs(i, v1, 1, v1[i]);
        // cout << i+1 << ": ";
        // for(auto x : enew[i]){
        //     cout << x << " ";
        // }
        // cout << "\n";
    }
    ans = (chk) ? (ans) : (-1);
    cout << ans << endl;
}

int main(){
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);
    solve();
}