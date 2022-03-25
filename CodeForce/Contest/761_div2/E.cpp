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
static T gcd (T a, T b) {long r, i;while(b!=0){r = a % b;a = b;b = r;}return a;}

template<typename T>
inline T lcm(T x, T y ){return x*y/gcd(x,y);}

template<typename T>
inline T findLessPower(T base, T n){if(n==1){return 0;} T temp = log(n)/log(base); if(power(base, temp) == n){return temp-1;}else{return temp;}}

const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;

int read(int a, int b, int c){
    cout << "? " << a << " " << b << " " << c << endl;
    cout.flush();
    int k;
    cin >> k;
    return k;
}


void solve(){
    ll n;
    cin >> n;
    ll k = n/3;
    int ans[n+1];
    int b[k+1];
    mem(ans, 0);
    mem(b, 0);
    int index;
    for(int i = 1; i < n; i+=3){
        int res = read(i, i+1, i+2);
        b[(i+2)/3] = res;
    }
    for(int i = 1; i < k; i++){
        if(b[i] != b[i+1]){
            index = i;
            break;
        }
    }
    vi temp(4, 0);
    temp[0] = b[index];
    for(int i = 1; i < 3; i++){
        temp[i] = read(index*3-2+i, index*3-2+i+1, index*3-2+i+2);
    }
    temp[3] = b[index+1];
    int im, cr;
    for(int i = 0; i < 3; i++){
        if(temp[i] != temp[i+1]){
            index = index*3 - 2 + i; 
            if(temp[i] == 0){
                im = index; 
                cr = index+3;
            } else {
                im = index+3;
                cr = index;
            }
            break;
        }
    }
    int cnt = 0;
    vi res;
    ans[im] = 0;
    ans[cr] = 1;
    for(int i = 0; i < k; i++){
        if(i*3+1 <= cr && cr <= i*3+3){
            if(cr == i*3+1){
                ans[i*3+2] = read(i*3+2, cr, im);
                ans[i*3+3] = read(i*3+3, cr, im);
            } else if(cr == i*3+2){
                ans[i*3+1] = read(i*3+1, cr, im);
                ans[i*3+3] = read(i*3+3, cr, im);
            } else {
                ans[i*3+1] = read(i*3+1, cr, im);
                ans[i*3+2] = read(i*3+2, cr, im);
            }
            for(int j = 1; j <= 3; j++){
                if(!ans[i*3+j]){res.push_back(i*3+j);cnt++;}
            }
            continue;
        }
        if(i*3+1 <= im && im <= i*3+3){
            if(im == i*3+1){
                ans[i*3+2] = read(i*3+2, cr, im);
                ans[i*3+3] = read(i*3+3, cr, im);
            } else if(im == i*3+2){
                ans[i*3+1] = read(i*3+1, cr, im);
                ans[i*3+3] = read(i*3+3, cr, im);
            } else {
                ans[i*3+1] = read(i*3+1, cr, im);
                ans[i*3+2] = read(i*3+2, cr, im);
            }
            for(int j = 1; j <= 3; j++){
                if(!ans[i*3+j]){res.push_back(i*3+j);cnt++;}
            }
            continue;
        }
        if(b[i+1] == 0){
            int moc = read(i*3+1, i*3+2, cr);
            if(moc == 1){
                ans[3*i+1] = read(i*3+1, im, cr);
                if(ans[3*i+1] == 1){
                    ans[i*3+2] = 0;
                    ans[i*3+3] = 0;
                } else{
                    ans[i*3+2] = 1;
                    ans[i*3+3] = 0;
                }
            } else {
                ans[i*3+1] = 0;
                ans[i*3+2] = 0;
                ans[i*3+3] = read(i*3+3,cr,im);
            }
        } else{
            int moc = read(i*3+1, i*3+2, im);
            if(moc == 1){
                ans[3*i+1] = 1;
                ans[i*3+2] = 1;
                ans[i*3+3] = read(cr,im, i*3+3);
            } else {
                ans[3*i+1] = read(i*3+1, im, cr);
                if(ans[3*i+1] == 1){
                    ans[i*3+2] = 0;
                    ans[i*3+3] = 1;
                } else {
                    ans[i*3+2] = 1;
                    ans[i*3+3] = 1;
                }
            }
        }

    }
    // for(int i = 1; i <= n; i++){
    //     if(ans[i] == 0){res.push_back(i); cnt++;}
    // }
    cout << "! ";
    queue<int> q;
    for(int i=1; i<=n; i++) if(ans[i] == 0) q.push(i);
    cout << q.size();
    while(q.size()) {
        cout << " " << q.front();
        q.pop();
    }
    cout << endl;
    // cout << index << " " << index+3 << endl;
    cout.flush();
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

