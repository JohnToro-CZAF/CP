#include<bits/stdc++.h>

using namespace std;


void solve(){
    vector<long long> c;
    vector<pair<long long, long long> > v;
    vector<pair<pair<long long, long long>, long long> > u;
    int n;
    cin >> n;
    if(n==1){
        long long t;
        cin >> t;
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    long long a[n+3];
    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        pair<long long, long long> u = make_pair(t, i);
        v.push_back(u);
    }
    sort(v.begin(), v.end());
    v.push_back(make_pair(0, 0));
    long long tsum = 0;
    long long r = 0;
    for(long long i = 1; i < v.size(); i++){
        if(v[i-1].first == v[i].first){
            tsum += v[i-1].first;
            r++;
        } else {
            tsum += v[i-1].first;
            r++;
            pair<long long, long long> t1 = make_pair(v[i-1].first, tsum);
            pair<pair<long long, long long>, long long> t2 = make_pair(t1, r);
            u.push_back(t2);
            r = 0;
        }
    }
    
    long long s = u.size();
    long long ans = 0;
    long long index;
    ans += u[s-1].second;
    if(s > 1){
        for(long long i = s-1; i > 0; i--){
            // cout << "check: " << u[i].first.first << " " << u[i].first.second << endl;
            if(u[i-1].first.second >= u[i].first.first){
                ans += u[i-1].second;
                index = u[i-1].first.first;
                // cout << index << endl;
            } else {
                index = u[i].first.first;
                // // cout << "1: ";
                // // cout << index << endl;
                break;
            }
        }
    } else {
        index = u[0].first.first;
    }
    // cout << s << endl;
    // cout << "index: " << index << endl;
    for(auto x : v){
        if(x.first >= index){
            c.push_back(x.second);
        }
    }
    cout << ans << endl;
    // cout << index << endl;
    sort(c.begin(), c.end());
    for(long long i = 0; i < c.size(); i++){
        cout << c[i]+1 << " ";
    }
    cout << "\n";
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
}