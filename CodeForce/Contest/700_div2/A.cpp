#include<bits/stdc++.h>

using namespace std;

void solve(){
    string s;
    cin >> s;
    for(int i = 0; i <s.size(); i++){
        if(i % 2 == 0){
            if(s[i] == 'a'){
                s[i] = 'b';
            } else {
                s[i] = 'a';
            }
        }
        if(i % 2 == 1){
            if(s[i] == 'z'){
                s[i] = 'y';
            } else {
                s[i] = 'z';
            }
        }
    }
    for(int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    cout << "\n";
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}