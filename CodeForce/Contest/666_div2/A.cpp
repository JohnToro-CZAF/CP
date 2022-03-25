#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    multiset<char> v;
    for(int i = 0; i<n; i++){
        string s;
        cin >> s;
        for(int j =0; j < s.size(); j++){
            v.insert(s[j]);
        }
    }
    bool chk = true;
    for(auto & x :v){
        if(v.count(x) % n != 0){
            chk =false;
            break;
        }
    }
    (chk) ? (puts("YES")) : (puts("NO"));
    cout << "\n";
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}