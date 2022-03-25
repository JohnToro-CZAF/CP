#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    for(int i =0; i<n; i++){
        cin >> a[i];
    }
    vector<int> v;
    int  cur = 0;
    for(int i = 0; i<n; i++){
        if(a[i] == a[i+1]){
            cur++;
        } else{
            v.push_back(cur+1);
            cur = 0;
        }
    }
    int ans = 0;
    for(int i =0; i < v.size(); i++){
        ans = max(ans, v[i]);
    }
    cout << ans <<endl;
}

int main(){
    int c;
    cin >> c;
    while (c--)
    {
        solve();
    }
    
}
