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
const int maxn = 1e5+8;
int cnt[maxn][26];
int cnt1[maxn][26];
void solve(){
    int n, m;
    cin >> n >> m;
    forn(i, m){
        forn(j, 26){
            cnt[i][j] = 0;
            cnt1[i][j] = 0;
        }
    }
    string ans;
    forn(i, n){
        string s;
        cin >> s;
        forn(j, m){
            int temp = s[j] - 'a';
            cnt[j][temp]++;
        }
    }
    forn(i, n-1){
        string s;
        cin >> s;
        forn(j, m){
            int temp = s[j] - 'a';
            cnt1[j][temp]++;
        }
    }
    forn(i, m){
        forn(j, 26){
            if(cnt1[i][j] != cnt[i][j]){
                char t = j + 'a';
                ans += t;
                // break;
            }
        }
    }
    // cout << 'z' - 'a' << endl;
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

