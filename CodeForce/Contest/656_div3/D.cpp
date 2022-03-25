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

const int maxn = 2e5+13;

int n;
char s[maxn];
char t[26];

int cal(int l, int r, int d){
    int ans = 0;
    char c = t[d%26]; 
    // cout << l << " " << r << " " << c << endl;
    if(l == r){
        if(s[l] == c){
            return 0;
        } else {
            return 1;
        }
    }
    int cl = 0;
    int cr = 0;
    int mid = r-l+1;
    for(int i = l; i <= (l+r-1)/2; i++){
        if(s[i] != c) cl++;
    }
    for(int i = (l+r+1)/2; i<=r; i++){
        if(s[i] != c) cr++;
    }
    cl += cal((l+r+1)/2, r, d+1);
    cr += cal(l, (l+r-1)/2, d+1);
    return min(cl, cr);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    for(int i = 0; i< 26; i++){
        t[i] = 'a' + i;
    }
    while(c--){
        int ans;
        cin >> n;
        string u;
        cin >> u;
        for(int i = 0; i < n; i++){
            s[i+1] = u[i];
            // cout << s[i+1] << " ";
        }
        int x = cal(1,n,0);
        cout << x << endl;
    }
}

