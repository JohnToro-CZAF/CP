#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    int a[n], b[n];
    int c[m];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < m; i++){
        cin >> c[i];
    }
    multiset<int> s, r;
    for(int i = 0; i < n; i++){
        // if(a[i] != b[i]){
        s.insert(b[i]);
            // cout << b[i] << " ";
        // }
    }
    // cout <<"\n";
    int temp = 0;
    for(int i = 0; i < m; i++){
        if(s.count(c[i]) != 0){
            r.insert(c[i]);
        }
    }
    // // for(auto it = s.begin(); it != s.end(); it++){
    // //     cout << *it << " ";
    // // }
    // cout << "\n";
    for(int i = 0; i < m; i++){
        if(s.count(c[i]) == 0){
            temp++;
            // cout << temp << endl;
        }
        if(temp > 0 && r.count(c[i]) > 0){
            temp--;
            r.erase(c[i]);
            // cout << "OPK" << endl;
        }
    }
    if(temp == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < m; i++){
        if(s.count(c[i]) != 0){
            r.insert(c[i]);
        }
    }
    vector<pair<pair<int, int> , veector<int> > > v;
    for(int i = 0) 
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}