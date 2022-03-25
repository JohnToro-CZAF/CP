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
    for(int i = 1; i < n+1; i++){
        if(a[i] == a[i-1]){
            t++;
        } else {
            v.push_back(t);
            t = 1;
        }
    }
    sort(v.begin(), v.end());
    int s = v.size();
    long long sum = 0;
    vector<long long> dp;
    for(int i = 0; i <s; i++){
        sum += v[i];
        dp.push_back(sum);
    } 
    vector<long long> ans;
    if(s == 1){
        cout << 0 << endl;
        return;
    }

    for(int i = v[0]; i <= v[s-1]; i++){
        int l = 0; int r = s-1;
        int res;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if(v[mid] <= i){
                res = mid;
                l = mid + 1;
            } else {
                r = mid -1;
            }
        }
        cout << i << " " << res << endl;
        int index = res;
        long long x = dp[index] + (dp[s-1] - dp[index]-i*(s-1-index));
        cout << x << endl;
        // cout << x <<endl;
        ans.push_back(x);
    }
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