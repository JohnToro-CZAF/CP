#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define forn(i,n) for(int i=0;i<n;++i)
#define mem(a,b) memset(a, (b), sizeof(a))

inline int gcd(int a, int b){while(b){b^=a^=b^=a%=b;} return a;}


const int maxn = 2e5 + 5;

int dp[maxn][20];
int n;
int a[maxn];
bool chk(int len){
    bool flag = true;
    vi v;
    for(int i = 0; i < n; i++){
        int temp = len; int x = i; int res = dp[i][0];
        for(int j = 19; j >=0; j--){
            if(temp >= (1<<j)){
                temp -= (1<<j);
                res = gcd(res, dp[x%n][j]);
                x += (1<<j);
            }
        }
        if(v.size() == 0){
            v.push_back(res); 
        } else {
            if(res != v.back()) return false;
            else v.push_back(res);
        }
    }
    return flag;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        cin >> n;
        // memset(dp, 0,sizeof(dp));
        forn(i, n){
            forn(j, 21){
                dp[i][j] = 0;
            }
        }
        forn(i, n){
            cin >> a[i];
            dp[i][0] = a[i];
        }
        for(int i = 1; i < 20; i++){
            for(int j = 0; j + (1<<i) - 1 < 2*n; j++){
                dp[j%n][i] = gcd(dp[j%n][i-1], dp[(j+(1<<(i-1)))%n][i-1]);
            }
        }
        int high = n; int low = 1; int res = 0;
        while(low <= high){
            int mid = (low+high)>>1;
            if(!chk(mid)){
                res = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        cout << res << endl;
    }
}

