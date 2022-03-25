#include<bits/stdc++.h>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        int n,x;
        cin >> n;
        int a[n];
        vector<vector<int> > v(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = 0; j< a[i]; j++){
                cin >> x;
                v[x-1].push_back(i);
            } 
        }
        int cnt = 0;
        int ans = 0;
        set<int> q;
        while(!s.empty())    
        // cout << "\n";
        // cout << "cnt" << cnt << endl;
        if(cnt < n){
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}

