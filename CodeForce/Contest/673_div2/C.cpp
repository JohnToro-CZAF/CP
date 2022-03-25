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

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const int INF = 1e9;
bool cmp(pair<int, int> const& a, pair<int, int> const& b)
{
    // For instance...
    if(a.first == b.first){
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}
void solve(){
    int n;
    cin >> n;
    vii v(n+1);
    vector<vector<int> > pos(n+1);
    int a[n];
    // cout << "start" << endl;
    forn(i, n){
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for(int i = 0; i <= n; i++){
        v[i] = make_pair(-1, i);
    }
    for(int i = 0; i <= n; i++){
        // cout << "\n";
        if(int(pos[i].size()) == 0){continue;}
        else{v[i].first = 0;}
        for(int j = 0; j < int(pos[i].size())-1; j++){
            int temp = pos[i][j+1] - pos[i][j];
            v[i].first = max(temp, v[i].first);
        }
        int t = int(pos[i].size());
        if(int(pos[i].size() != 0)){
            v[i].first = max(v[i].first, *pos[i].begin()+1);
            v[i].first = max(v[i].first, n-*(pos[i].end()-1));
        }
    }
    sort(all(v));
    int b[n+1];
    memset(b, -1, sizeof(b));
    vii v1;
    for(int i = 0; i < int(v.size()); i++){
        if(v[i].first != -1){
            v1.push_back(v[i]);
        }
    }
    int m = int(v1.size()-1);
    for(int i = 0; i < int(v1.size()); i++){
        // cout << v1[i].first << " " << v1[i].second << endl;
    }
    pii best = make_pair(v1[0].first, v1[0].second);
    for(int i = 0; i < int(v1.size()); i++){
        if(v1[i].second < best.second){
            best = v1[i];
        }
        b[v1[i].first] = best.second;
    }
    for(int i = 0; i < int(v1.size())-1; i++){
        for(int j = v1[i].first; j < v1[i+1].first; j++){
            b[j] = b[v1[i].first];
        }
    }
    for(int i = v1[int(v1.size()-1)].first; i <= n; i++){
        b[i] = b[v1[m].first];
    }
    // for(int i = 1; i <= n; i++){
    //     if(v[t].first)
    //     // auto down = upper_bound(v.begin(), v.end(), make_pair(i, 0), cmp);
    //     // if(down != v.end()){
    //     //     b[i] = down->second;
    //     //     cout << i << "here" << b[i] << endl;
    //     // }
    //     // else continue;
    // }
    for(int i = 1; i <= n; i++){
        cout << b[i] << " ";
    }
    cout << "\n";
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

