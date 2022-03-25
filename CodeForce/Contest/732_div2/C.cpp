#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

void solve(){   
    int n;
    cin >> n;
    int a[n+1];
    forn(i, n){
        cin >> a[i];
    }
    a[n] = 0;
    vector<pair<int, int> > v;
    forn(i, n){
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    // v.push_back(make_pair(0, 0));
    sort(a, a+n);
    bool flag = true;
    int i = 0;
    while(i != n){
        ll cursum = i % 2;
        ll cursum1 = v[i].second % 2;
        while(a[i] == a[i+1] && i < n){
            cursum += (i+1)%2;
            cursum1 += (v[i+1].second)%2;
            i++;
        }
        // cout << cursum1 << " " << cursum << endl;
        if(cursum1 != cursum){
            flag = false;
            // break;
        }
        i++;
    }
    if(flag){
        cout << "YES" << endl; 
    } else {
        cout << "NO" << endl;
    }
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

