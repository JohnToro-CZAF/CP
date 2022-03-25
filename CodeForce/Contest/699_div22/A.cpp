#include<bits/stdc++.h>

using namespace std;

void solve(){
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;
    int n = s.size();
    int a = 0, b = 0, c = 0, d = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R'){
            a++;
        }
        if(s[i] == 'L'){
            b++;
        }
        if(s[i] == 'U'){
            c++;
        }
        if(s[i] == 'D'){
            d++;
        }
    }
    if(x == 0 && y == 0){
        cout << "YES" << endl;
        return;
    }
    if(x == 0 && y > 0){
        if(c >= abs(y)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(x == 0 && y < 0){
        if(d >= abs(y)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(x > 0 && y > 0){
        if(c >= abs(y) && a>= abs(x)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(x > 0 && y < 0){
        if(d >= abs(y) && a >= abs(x)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(y == 0 && x > 0){
        if(a >= abs(x)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(y == 0 && x < 0){
        if(b >= abs(x)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(y < 0 && x < 0){
        if(b >= abs(x) && d >= abs(y)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
    if(y > 0 && x < 0){
        if(c >= abs(y) && b >= abs(x)){
            cout << "YES" << endl;
            return;
        } else {
            cout << "NO" << endl;
            return;
        }
    }
}

int main(){
    ios :: sync_with_stdio (0);
    cin.tie (0);  cout.tie (0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}