#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
#define allr(a) (a).rbegin(), (a).rend()
#define foreach(a) for(auto it = a.begin(); it != a.end(); it++)
#define mem(a,b) memset(a, (b), sizeof(a))
template<typename T>
inline T cei(T x, T y){T t = (x+y-1)/y;return t;}

template<typename T>
inline T power(T base, T powerRaised){if (powerRaised != 0) return (base*power(base, powerRaised-1)); else return 1;}

template<typename T>
inline T gcd(T a, T b){while(b){b^=a^=b^=a%=b;} return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

int ch[maxn];
void solve(){
    ll n,k,x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    s += '$';
    mem(ch, 0);
    vector<ll> v;
    string cop;
    int i = 0;
    if(x == 0){
        cout << s << endl;
        return;
    }
    int number = 0;
    while(i!=n){
        if(s[i] == '*'){
            int cnt = 1;
            while(s[i] == '*' && s[i+1] == '*'){
                cnt++;
                i++;
            }
            v.push_back(cnt*k);
            number++;
            cop += '*';
        } else {
            cop += 'a';
        }
        i++;
    }
    int l = int(v.size());
    vector<ll> temp;
    ll t = 1;
    for(int i = l-1; i >= 0; i--){
        temp.push_back(v[i]+1);
        t *= v[i]+1;
    }
    temp.push_back(INF);
    reverse(all(temp));
    int index;
    ll remain;
    vector<ll> ann(l+4, 0);
    x--;
    for(int i = int(temp.size())-1; i >= 0; i--){
        ann[i] = x%temp[i];
        x /= temp[i];
    }
    int cnt = 0;
    string ans = "";
    for(int i = 0; i < cop.size(); i++){
        if(cop[i] == '*'){
            cnt++;
            ans += string(ann[cnt], 'b');
        } else ans+='a';
    }
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

