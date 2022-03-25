#include<bits/stdc++.h>

using namespace std;

void solve(){
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    set<char> c;
    for(long long i = 0; i < k; i++){
        char t;
        cin >> t;
        c.insert(t);
    }
    s.push_back('0');
    vector<long long> v;
    long long r = 0;
    for(long long i = 0; i < s.size(); i++){
        if(c.count(s[i]) != 0){
            r++;
        } else {
            v.push_back(r);
            r = 0;
        }
    }
    long long ans = 0;
    for(auto x : v){
        // cout << x << endl;
        ans += (x+1)*x/2;
    }
    cout << ans << endl;
}

int main(){
    solve();
}