#include<bits/stdc++.h>
#include<string>
using namespace std;

void converse(long &n, string & ans){
    if(n == 0){
        return;
    }
    int x = n%26;
    string t = to_string(x);
    n /= 26;
    ans.insert(0, t);
    converse(n, ans);
}

void solve(){
    long sR;
    string s;
    string colAns;
    cin >> s;
    for(int  i= 0; i <s.size(); i++){
        if(s[i] == 'C'){
            sR = i-1;
            break;
        }
    }
    long row = stoi(s.substr(1, sR));n
    long col = stoi(s.substr(sR+2, s.size() - 2 - sR)); 
    converse(col, colAns);
    for(int i =0; i < colAns.size(); i++){
        int ai = colAns[i];
        char c = '0' + ai;
        c = toupper(c);
        cout << c;

    }
    cout <<row;
    // cout << row;
    cout << "\n";
     
}

int main() {
    int n;
    cin >> n; 
    while(n--){
        solve();
    }
}