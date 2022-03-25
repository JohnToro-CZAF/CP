#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long a[n+3];
    multiset<int> s;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(s.count(a[i]) == 0){
            s.insert(a[i]);
        } else {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}