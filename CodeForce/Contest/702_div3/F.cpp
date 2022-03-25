#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    long long a[n+1];
    for(int i = 0; i <n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    a[n] = 0;
    vector<int> v;
    int t = 1;
    set<int> dp;
    for(int i = 1; i < n+1; i++){
        if(a[i] == a[i-1]){
            t++;
        } else {
            v.push_back(t);
            dp.insert(t);
            t = 1;
        }
    }
    sort(v.begin(), v.end());
    int s = v.size();
    // long long sum = 0;
    // vector<long long> dp;
    // for(int i = 0; i <s; i++){
    //     sum += v[i];
    //     dp.push_back(sum);
    // } 
    vector<long long> ans;
    if(s == 1){
        cout << 0 << endl;
        return;
    }
    // long long p = 0;
    // long long h = sum - (s-1)*v[0];
    // for(int i = 0; i < s; i++){
    //     cout << v[i] << " ";
    // }
    // cout << "\n";
    
    for(auto x: dp){
        long long temp = 0;
        for(auto y : v){
            if(y >= x){
                temp += (y-x);
            } else {
                temp += y;
            }
        }
        ans.push_back(temp);
    }

    // for(int i = v[0]; i <= v[s-1]; i++){
    //     int l = 0; int r = s-1;
    //     while (l < r-1)
    //     {
    //         int mid = (l+r)/2;
    //         if(v[mid] == i){
    //             l = mid;
    //             break;
    //         }
    //         if(v[mid] < i){
    //             l = mid;
    //         } else {
    //             r = mid;       
    //         }
    //     }
    //     cout << i << " " << l << endl;
    //     int index = l;
    //     long long x = dp[index] + (dp[s-1] - dp[index]-i*(s-1-index));
    //     // cout << x <<endl;
    //     ans.push_back(x);
    // }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}