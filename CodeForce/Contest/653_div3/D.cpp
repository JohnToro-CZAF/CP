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
const int maxn = 2e5+9;
int a[maxn];

void solve(){
    map<int, int> fre;
    long long n,k;
    cin >> n >> k;
    // memset(re, 0, sizeof(re));
    // memset(fre, 0, sizeof(fre));
    set<int> s;
    bool flag = true;
    forn(i, n){
        cin >> a[i];
        if(a[i] % k != 0){
            flag = false;
        }
    }
    if(flag){
        cout << 0 << endl;
        return;
    }
    forn(i, n){
        int temp = cei(a[i],k)*k - a[i];
        // if(re[i] == 0) re[i] = k;
        if(temp == 0) continue;
        fre[temp]++;
        s.insert(temp);
        // cout << re[i] << " ";
    }
    // cout << "\n";
    vector<pair<long long, long long> > v;
    for(auto &x : s){
        v.push_back(make_pair(fre[x], x));
        // cout << fre[x] << " ";
    }  
    sort(v.begin(), v.end());
    long long ans = 0;
    for(int i = 0; i < v.size(); i++){
        ans = max(ans, v[i].first);
    } 
    vector<pair<long long, long long> > t;
    for(int i = 0; i < v.size(); i++){
        if(ans == v[i].first){
            t.push_back(make_pair(v[i].first, v[i].second));
        }
    }
    // cout << "loz " << endl;
    // cout << ans << endl;
    ans = 0;
    for(int i = 0; i < t.size(); i++){
        // cout << t[i].first << " " << t[i].second << endl;
        ans = max(ans, t[i].second);
    }
    // cout << "cac" << endl;
    // cout << t[0].first << endl;
    long long res = (k*(t[0].first-1)) + ans + 1;
    cout << res << endl;
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

