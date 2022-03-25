#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i =0; i <n; i++){
        int ai;
        cin >> ai;
        a.push_back(ai);
    }
    if(n == 1){
        cout <<"YES";
        return;
    }
    while(a.size()!= 1){
        int m = INT_MAX;
        for(int  i= 0; i< a.size(); i++){
            m = min(m, a[i]);
        }
        int indexm;
        for(int i = 0; i< a.size(); i++){
            if(a[i] == m){
                indexm = i;
                break;
            }
        }
        if(indexm == 0 && a[indexm+1] - a[indexm] <= 1){
            a.erase(a.begin()+indexm);
            continue;
        }
        if(indexm == a.size()-1 && a[indexm-1] - a[indexm] <= 1){
            a.erase(a.begin()+indexm);
            continue;
        }
        if((indexm != 0 && indexm != a.size()-1) && ((a[indexm+1] - a[indexm] <= 1) || (a[indexm-1] - a[indexm] <= 1) )){
            a.erase(a.begin()+indexm);
            continue;
        }
        if(indexm == 0 && a[indexm+1] - a[indexm] > 1){
            cout << "NO" << endl;
            return;
        }
        if(indexm == a.size()-1 && a[indexm-1] - a[indexm] > 1){
            cout << "NO" << endl;
            return;
        }
        if((indexm != 0 && indexm != a.size()-1) && ((a[indexm+1] - a[indexm] > 1) && (a[indexm-1] - a[indexm] > 1) )){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" <<endl;
}


int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

