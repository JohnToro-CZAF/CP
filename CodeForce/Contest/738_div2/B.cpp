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

char f(char c){
    if(c == 'R'){
        return 'B';
    } else {
        return 'R';
    }
}

void solve(){
    ll n;
    cin >> n;
    char s[200];
    vector<pair<char, int> > vec(200);
    int j = 1;
    int count = 0;
    forn(i, n){
        cin >> s[i+1];
        if(s[i+1] != '?'){
            vec[j] = make_pair(s[i+1], i+1);
            count++;
        }
    }
    j = 1;
    while(j != count - 1){
        if(vec[j].first == 'R' && vec[j+1].first == 'R' ){
            for(int i = vec[j].second + 1; i < vec[j+1].second; i++){
                if(i %2 == (vec[j].second + 1) % 2){
                    s[i] = 'B';
                } else {
                    s[i] = 'R';
                }
            }
        }
        if(vec[j].first == 'B' && vec[j+1].first == 'B' ){
            for(int i = vec[j].second + 1; i < vec[j+1].second; i++){
                if(i %2 == (vec[j].second + 1) % 2){
                    s[i] = 'R';
                } else {
                    s[i] = 'B';
                }
            }
        }
        if(vec[j].first == 'R' && vec[j+1].first == 'B' ){
            if(vec[j+1].second - vec[j].second % 2 == 0){
            for(int i = vec[j].second + 1; i < vec[j+1].second; i++){
                if(i %2 == (vec[j].second + 1) % 2){
                    s[i] = 'B';
                } else {
                    s[i] = 'R';
                }
            }
            }
            if(vec[j+1].second - vec[j].second % 2 == 1){
            for(int i = vec[j].second + 1; i < vec[j+1].second; i++){
                if(i %2 == (vec[j].second + 1) % 2){
                    s[i] = 'B';
                } else {
                    s[i] = 'R';
                }
            }
            }

        }
        if(vec[j].first == 'B' && vec[j+1].first == 'R' ){
            if(vec[j+1].second - vec[j].second % 2 == 0){
            for(int i = vec[j].second + 1; i < vec[j+1].second; i++){
                if(i %2 == (vec[j].second + 1) % 2){
                    s[i] = 'R';
                } else {
                    s[i] = 'B';
                }
            }
            }
            if(vec[j+1].second - vec[j].second % 2 == 1){
            for(int i = vec[j].second + 1; i < vec[j+1].second; i++){
                if(i %2 == (vec[j].second + 1) % 2){
                    s[i] = 'B';
                } else {
                    s[i] = 'R';
                }
            }
            }

        }
        j++;
    }
    if(vec[1].second %2 == 1){
        for(int i = 1; i < vec[1].second; i++){
            s[i] = (i%2) ? vec[1].second : f(vec[1].second);
        }
    } else {
        for(int i = 1; i < vec[1].second; i++){
            s[i] = (i%2) ? f(vec[1].second) : (vec[0].second);
        }
    }
    for(int i = vec[count].second+1; i <= n; i++){
        s[i] = (i%2 == vec[count].second+1 % 2) ? f(vec[count].second) : vec[0].second;
    }
    forn(i, n){
        cout << s[i+1];
    }
    cout  << "\n";
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

