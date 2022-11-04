#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
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

const ll maxn = 1e6 + 5;
const ll MOD = 1e9 + 7; // 998244353
const ll INF = 1e9;
const char min_char = 'a';
void solve(){
    int n;
    cin >> n;
    vector<int> mark(n, 0), l(n), r(n);

    vector<pii> nums;
    forn(i, n){
        int a;
        cin >> a;
        nums.push_back({a, i});
    }

    sort(all(nums));

    for (auto p: nums){
        cout << p.first << " " << p.second << "\n";
    }

    int pt = 0;
    ll ans = 0;
    for (ll i = 1; i <= maxn; i++){
        ll addi = 0;
        while (nums[pt].first <= i){
            pii curr = nums[pt];
            int ind = curr.second;
            // cout << pt << " " << curr.first << " " << ind << " " << i << "\n";
            mark[ind] = 1;
            if (ind == 0){
                if (mark[ind+1] == 1){
                    ll bef = r[ind+1] - l[ind+1]+1;
                    ll aft = bef + 1;
                    r[ind] = r[ind+1];
                    l[ind] = ind;
                    l[r[ind]] = ind;
                    addi = (aft * (aft + 1)) / 2 - (bef * (bef + 1)) / 2;
                }
                else{
                    addi += 1;
                }
            }

            if (ind == n-1){
                if (mark[ind-1] == 1){
                    ll bef = r[ind-1] - l[ind-1] + 1;
                    ll aft = bef + 1;
                    l[ind] = l[ind-1];
                    r[ind] = ind;
                    r[l[ind]] = ind;
                    addi = (aft * (aft + 1)) / 2 - (bef * (bef + 1)) / 2;
                }
                else{
                    addi += 1;
                    l[ind] = ind;
                    r[ind] = ind;
                }

            }

            if (0 < ind && ind < n-1){
                if (mark[ind-1] == 1 && mark[ind+1] == 1){
                    ll bef1 = r[ind-1] - l[ind-1] + 1;
                    ll bef2 = r[ind+1] - l[ind+1] + 1;
                    ll aft = bef1 + bef2 + 1;
                    l[r[ind+1]] = l[ind-1];
                    r[l[ind-1]] = r[ind+1];
                    addi += (aft * (aft+1)) / 2 - (bef1 * (bef1 + 1)) / 2 - (bef2 * (bef2 + 1)) / 2;
                }

                else if (mark[ind-1] == 1){
                    ll bef = r[ind-1] - l[ind-1] + 1;
                    ll aft = bef + 1;
                    l[ind] = l[ind-1];
                    r[ind] = ind;
                    r[l[ind]] = ind;
                    addi += (aft * (aft + 1)) / 2 - (bef * (bef + 1)) / 2;
                }
                else if (mark[ind+1] == 1){
                    ll bef = r[ind+1] - l[ind+1]+1;
                    ll aft = bef + 1;
                    r[ind] = r[ind+1];
                    l[ind] = ind;
                    l[r[ind]] = ind;
                    addi += (aft * (aft + 1)) / 2 - (bef * (bef + 1)) / 2;
                }
                else{
                    addi += 1;
                    l[ind] = ind;
                    r[ind] = ind;
                }
            }
            pt++;
            if (pt >= n) break;

        }            
        forn(i, n){
            cout << mark[i] << " ";
        }
        cout << "\n";
        forn(i, n){
            cout << l[i] << " ";
        }
        cout << "\n";
        forn(i, n){
            cout << r[i] << " ";
        }
        cout << "\n";
        cout << addi << " " << i << "\n";
        ans += addi * i;
        if (pt >= n) break;
    }

    cout << ans << "\n";
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

