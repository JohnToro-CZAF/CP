#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5+9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    multiset<int> b;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        b.insert(x);
    }
    for(int i = 0; i < n; i++){
        auto it = b.lower_bound(n - a[i]);
        if(it == b.end()){it = b.begin();}
        int ans = (a[i] + *it)%n;
        cout << ans << " ";
        b.erase(it);
    }
    cout << "\n";
    return 0;
}

