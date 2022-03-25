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

ll count(string t, char letter){
    string s = t;
    ll n = s.length();
    for(int i = 0; i < s.length(); i++){
        if(s[i] == letter){
            s[i] = '0';
        }
    }
    ll res = 0;

    bool flag = true;
    // forn(i, cei(n, 2)){
    //     if(s[i] != s[n-i-1] && (s[i] == 'A' || s[n-1-i] == 'A')){
    //         res += 1;
    //     }
    //     if(s[i] != s[n-1-i] && (s[i] != 'A' || s[n-1-i] != 'A')){
    //         break;
    //         flag = false;
    //     }
    // }
    ll i = 0, j = n-1;
    while(i<=j){
        // cout << "start" << i << " " << j << " " << res << endl;
        if(s[i] == '0'){
            if(s[i] != s[j]){
                res +=1;
                i++;
                continue;
            } else{
                i++;
                j--;
                continue;
            }
        }
        if(s[j] == '0'){
            if(s[i] != s[j]){
                res +=1;
                j--;
                continue;
            } else{
                i++;
                j--;
                continue;

            }
        }
        if(s[i] != s[j]){flag = false; break;}
        if(s[i] == s[j]){
            if(abs(i-j) == 1){
                break;
            }
            i++; j--;
        }
    }
    // cout << res << endl;
    if(flag) return res;
    else return -1;
}

void solve(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    set<char> s1;
    forn(i, n){
        s1.insert(s[i]);
    }
    ll res = 112020290;
    bool flag = false;
    for(auto c : s1){
        ll temp = count(s, c);
        // cout << c << " " << temp;
        if(count(s,c) >= 0){
            flag = true;
            res = min(res, temp);
        }
    }
    if(flag) cout << res << endl;
    else cout << -1 << endl;
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

