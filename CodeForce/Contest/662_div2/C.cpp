#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    map<int, int> m;
    forn(i, n){
        cin >> a[i];
        m[a[i]]++;
    }
    int q;
    cin >> q;
    while(q--){
        char c; int x;
        cin >> c >> x;
        if(c == '+') m[x]++;
        else m[x]--;
        map<int, int>::iterator it;
        it = m.end();
        it--;
        if(it->second >= 8){
            cout << "YES" << endl;
        } else {
            if(it != m.begin() && it->second >= 6 && (it-1)->second >= 2){
                cout << "YES" << endl;
            } else {
                if(it != m.begin() && it->second >= 4 && (it-1)->second >= 4){
                    cout << "YES" << endl;
                } else {
                    if(it != m.begin() && it-1 != m.begin() && it->second >= 4 && (it-1)->second>=2 && (it-2)->second >= 2){
                        cout << "YES" << endl;
                    } else {
                        cout << "NO" << endl;
                    }
                }
            }
        }
    }
}

