#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int b = 0;
    int c = 0;
    int d = 0;
    int t = n/3;
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 3 == 0){
            b++;
        } else if(a[i]%3 == 1){
            c++;
        } else {
            d++;
        }
    }
    if(b >= t && c >=t && d <= t){
        ans += (b-t)*2 + (c-t);
        cout << ans << endl;
        return;
    }

    if(c >= t && d >=t && b <= t){
        ans += (c-t)*2 + (d-t);
        cout << ans << endl;
        return;
    }
    if(d >= t && b >=t && c <= t){
        ans += (d-t)*2 + (b-t);
        cout << ans << endl;
        return;
    }
    if(d >= t && b <= t && c <= t){
        ans += (t-b) + (t-c)*2;
        cout << ans << endl;
        return;
    }
    if(b >= t && d <= t && c <= t){
        ans += (t-d)*2 + (t-c);
        cout << ans << endl;
        return;
    }
    if(c >= t && b <= t && d <= t){
        ans += (t-d) + (t-b)*2;
        cout << ans << endl;
        return;
    }
    cout << ans << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}