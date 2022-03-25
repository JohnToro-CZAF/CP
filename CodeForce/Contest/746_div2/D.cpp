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

int read(set<int> s){
    cout << "? ";
    cout << int(s.size()) << " ";
    for(int u : s){ 
        cout << u+1 << " ";
    }
    cout << endl;
    cout.flush();
    int k;
    cin >> k;
    return k;
}

void answer(pii a){
    cout << "! " << a.first+1 << " " << a.second+1 << endl;
    cout.flush();
}

vvi edge(maxn);
vii edges;

void eet(int s, int pre){
    if(pre != -1) {
        edges.push_back(make_pair(s, pre));
    }
    // cout << s << " ";
    for(int u : edge[s]){
        if(u == pre) continue;
        else {
            eet(u, s);
        }
    }
    if(pre != -1) {
        edges.push_back(make_pair(s, pre));
    }
}

void solve(){
    int n;
    cin >> n;
    forn(i, n-1){
        int x,y;
        cin >> x >> y;
        x--; y--;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    eet(0, -1);
    // cout << "loz" << endl;
    int low = 0, high = 2*n-3, res = 0, ans;
    cout << "? " << n << " ";
    for(int i = 0; i < n; i++){
        cout << i+1 << " ";
    }
    cout.flush();
    cin >> ans;
    while(low <= high){
        int mid = (low+high)>>1;
        set<int> s;
        for(int i = low; i <= mid; i++){
            s.insert(edges[i].first);
            s.insert(edges[i].second);
        }
        int rs = read(s);
        if(rs == ans){
            res = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    answer(edges[res]);
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

