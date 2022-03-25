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
    int a[n];
    int q;
    map<int, int> m;
    multiset<int> s;
    forn(i, n){
        cin >> a[i];
        m[a[i]]++;
    }
    for(auto x : m){
        s.insert(m[x.second]);
    }
    cin >> q;
    while(q--){
        char c; int x;
        cin >> c >> x;
        multiset<int>::iterator f;
        f = s.find(m[x]);
        if(c == '+'){
            m[x]++;
        } else {m[x]--;}
        s.erase(f);
        cout << "buoi " << endl;
        s.insert(m[x]);
        auto it = s.upper_bound(8);
        cout << "cac" << endl;
        if(it!=s.end()){
            cout << "YES" << endl;
        } else {
            auto it2 = s.upper_bound(2);
            auto it6 = s.upper_bound(6);
            if(it2 != it6 && it2 != s.end() && it6 != s.end()){
                cout << "YES" << endl;
            } else {
                auto it4 = s.upper_bound(4);
                if(it4 != s.end() && ++it4 != s.end()){
                    cout << "YES" << endl;
                } else {
                    auto it2 = s.upper_bound(2);
                    auto it6 = s.upper_bound(6);
                    auto it21 = it2++;
                    it2--;
                    if((it2!=s.end() &&it21!=s.end() &&it6!=s.end())&&(it2!=it6&&it21!=it6)){
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}

