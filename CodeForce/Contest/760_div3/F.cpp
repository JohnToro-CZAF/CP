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
inline T gcd(T x, T y){ T ans = x; T temp = y; while(ans != temp){if(ans < temp){ temp -= ans;} else{ans -= temp;}} return ans;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

#define INT_SIZE sizeof(int) * 8
 
// Function to reverse bits of a given integer
ll reverseBits(ll n){
    ll val = 0 ;
    ll h = n ;
    while(h > 0){
        val = val * 2 + h % 2 ;
        h = h >> 1;
    }
    return val;
}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

string bitR(ll x){
    string ans = "";
    while(x > 0){ans += char('0'+x%2); x/=2;};
    // cout << "fuck";
    reverse(all(ans));
    return ans;
}

string go(string s){
    while(s.back() == '0'){s.pop_back();}
    reverse(all(s));
    return s;
}


void solve(){
    ll x, y;
    cin >> x >> y;
    // cout << bitR(x) << endl;
    set<string> used;
    queue<string> q;
    string t = bitR(x);
    q.push(t);
    while(!q.empty()){
        // cout << "DU" << endl;
        string t = q.front();
        q.pop();
        if(t.size() > 100 || used.find(t) != used.end()) continue;
        used.insert(t);
        for(int i = 0; i < 2; i++){
            string n = (t+char('0'+i%2));
            q.push(go(n));
        }
    }
    if(used.find(bitR(y))!= used.end()){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

