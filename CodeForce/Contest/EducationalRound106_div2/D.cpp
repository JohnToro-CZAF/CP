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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = 2e7 + 13;
    vector<int> mind(N, -1), val(N);
    for(int i = 2; i < N; i++){
        if(mind[i] == -1){
            for(int j = i; j < N ;j+=i){
                if(mind[j] == -1) mind[j] = i;
            }
        }
    }
    for(int i = 2; i < N; i++){
        int j = i/mind[i];
        val[i] = val[j] + (mind[i] != mind[j]);
    }
    int c;
    cin >> c;
    while(c--){
        ll ans = 0;
        int c,d,x;
        cin >> c >> d >> x;
        for(int i = 1; i*i <= x; i++){
            if(x%i == 0){
                int t = x/i + d;
                if(t % c == 0){
                    ans += 1 << val[t/c];
                }
                if(i*i == x) continue;
                t = i + d;
                if(t%c == 0) {ans += (1 << val[t/c]);}
            }
        }
        cout << ans << endl;
    }

}

