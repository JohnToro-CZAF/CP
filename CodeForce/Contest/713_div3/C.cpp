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

void solve(){
    int n,a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    n = s.length();
    int i = 0;
    int j = n-1;
    int c = 0;
    int k = n/2;
    if(n == 1){
        if(s[0] == '?'){
            if(a == 1) {cout << '0' << endl; return;}
            if(b == 1) {cout << '1' << endl; return;}
            cout << -1 << endl; return;
        } else if(s[0] == '0'){
            if(a == 1) {cout << '0' << endl; return;}
            if(b == 1) {cout << -1 << endl; return;}
        } else {
            if(b == 1) {cout << '1' << endl; return;}
            if(a == 1) {cout << -1 << endl; return;}           
        }
    }
    while(i < j){
        if(s[i] != s[j]){
            if(s[i] != '?' && s[j] != '?') {cout << -1 << endl; return;}
            else if(s[i] == '0' || s[j] == '0'){
                a-= 2;
                if(s[i] == '?') s[i] = '0';
                else s[j] = '0';
            }
            else{
                b-= 2;
                if(s[i] == '?') s[i] = '1';
                else s[j] = '1'; 
            };
        } else {
            if(s[i] == '0') a-=2;
            else if(s[i] == '1') b-=2;
            else c +=2;
        }
        i++;
        j--;
    }
    // cout << s << endl;
    // cout << a << " " << b << " " << c << endl;
    if(n%2 == 0){
        if(a+b == c && a % 2 == 0 && b %2 == 0){
            for(int i = 0; i < k; i++){
                if(s[i] == s[n-1-i] && s[i] == '?'){
                    if(a != 0){s[i] = '0'; s[n-1-i] = '0'; a-=2;}
                    else {s[i] = '1'; s[n-1-i] = '1'; b-=2;}
                }
            }
            forn(i,n) cout << s[i];
            cout << "\n";
            return;
        } else {
            cout << -1 << endl;
        }
    } else {
        if(s[k] == '?'){ c++;}
        else {if(s[k] == '0')a--; else b--;}
        // cout << "Hoang " << a << " " << b << " " << c << endl;
        if(a+b == c){
            // cout << s << endl;
            if(s[k] == '?'){
                if(a % 2 == 1){s[k] = '0'; a--;}
                else {s[k] = '1'; b--;}
            }
            for(int i = 0; i < k; i++){
                if(s[i] == s[n-1-i] && s[i] == '?'){
                    if(a != 0){s[i] = '0'; s[n-1-i] = '0';}
                    else {s[i] = '1'; s[n-1-i] = '1';}
                }
            }
            cout << s << endl;
        } else {cout << -1 << endl;}
}
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

