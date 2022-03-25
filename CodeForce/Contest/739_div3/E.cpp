#include<bits/stdc++.h>
#include<string.h>

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
    string t;
    cin >> t;
    int n = t.length();
    // cout << "buoi " << endl;
    map<char, int> freq;
    map<char, int> last_occur;
    vector<pair<int, char> > last_occ;
    forn(i, n){
        last_occur[t[i]] = i;
        freq[t[i]]++;
    }
    for(auto &x : last_occur){
        last_occ.push_back(make_pair(x.second, x.first));
        // cout << x.first << " " << x.second;
    }
    string order;
    int length = 0;
    sort(last_occ.begin(), last_occ.end());
    for(int i = 0; i < last_occ.size(); i++){
        char c = last_occ[i].second;
        order += c;
        // cout << c << endl;
        if(freq[c] % (i+1) != 0){
            cout << -1 << endl;
            return;
        }
        length += freq[c]/(i+1);
    }
    string ans = t.substr(0, length);
    string s;
    for(int i = 0; i < order.size(); i++){
        s += ans;
        ans.erase(remove(ans.begin(), ans.end(), order[i]), ans.end());
    }
    if(t != s){
        cout << -1 << endl;
        return;
    }
    cout << t.substr(0, length) << " " << order << endl;
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

