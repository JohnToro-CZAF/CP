#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i);
#define per(i,r,l) for(int i=r;i>=l;--i);
#define rep0(i,l,r) for(int i=l;i<r;++i);
#define forn(i,n) for(int i=0;i<n;++i);
#define all(a) (a).begin(), (a).end();
#define allr(a) (a).rbegin(), (a).rend();
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++);
#define mem(a,b) memset(a, (b), sizeof(a));
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

void solve(){
    int n, m;
    cin >> n >> m;
    ll cnt = (1ll << (m-1))-1;
    ll cnt1 = (1ll << (m-1));
    ll cur = (1ll << (m-1))-1;
    // cout << "start" << endl;
    set<ll> number;
    while(n--){
        string s;
        cin >> s;
        ll now = 0;
        for(ll i = 0; i < m; i++){
            if(s[i] == '1') now += (1ll<<(m-i-1));
        }
        number.insert(now);
        if(now > cur){
            cnt1--;
            if(cnt < cnt1-1){
                cur++;
                while(number.find(cur) != number.end()){
                    cur++;
                } 
                cnt++;
                cnt1--;
                continue;
            }
            if(cnt1 < cnt){
                cur--;
                while(number.find(cur) != number.end()){
                    cur--;
                } 
                cnt1++;
                cnt--;
                continue;
            }
        } else if(now < cur){
            cnt--;
            if(cnt < cnt1-1){
                cur++;
                while(number.find(cur) != number.end()){
                    cur++;
                } 
                cnt++;
                cnt1--;
                continue;
            } 
            if(cnt1 < cnt){
                cur--;
                while(number.find(cur) != number.end()){
                    cur--;
                }
                cnt1++;
                cnt--;
                continue;
            }
        } else {
            if(cnt == cnt1){
                cur--;
                while(number.find(cur) != number.end()){
                    cur--;
                }
                cnt--;
                continue;
            }
            if(cnt < cnt1){
                cur++;
                while(number.find(cur) != number.end()){
                    cur++;
                }
                cnt1--;
                continue;
            }
            if(cnt > cnt1){
                cur--;
                while(number.find(cur) != number.end()){
                    cur--;
                }
                cnt--;
                continue;
            }
        }
        // cout << "test" << endl;
        // cout << now << " " << cur << endl;
        // cout << cnt << " " << cnt1 << endl;
    }
    for(ll i = m-1; i >= 0; i--){
        if((cur >> (i)) & 1){
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << "\n";
    // cout << cur << endl;
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

