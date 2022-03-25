#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

vector<int> l;
vector<int> r;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    l.clear();
    r.clear();
    int n;
    cin >> n;
    int a[n];
    forn(i, n){
        cin >> a[i];
    }
    l.push_back(a[0]);
    r.push_back(a[n-1]);
    for(int i = 0; i< n-1; i++){
        if(a[i] < a[i+1]){
            l.push_back(a[i+1]);
        } else {
            break;
        }
    }
    for(int i = n-1; i >= 1; i--){
        if(a[i-1] > a[i]){
            r.push_back(a[i-1]);
        } else{
            break;
        }
    }
    // for(auto &x: l){
    //     cout << x  << " ";
    // }
    // cout << "\n";
    // for(auto &x: r){
    //     cout << x  << " ";
    // }
    // cout << "\n";
    int i = 0;
    int j = 0;
    int ans = 0;
    vector<char> code;
    bool flag = false;
    while(i < l.size() && j < r.size()){
        // cout << i << " " << j << endl;
        if(l[i] < r[j]){
            code.push_back('L');
            ans++;
            i++;
        }
        if(l[i] > r[j]){
            code.push_back('R');
            ans++;
            j++;
        }
        if(l[i] == r[j]){
            flag  = true;
            if(l.size() - i >= r.size() - j){
                for(int x = i; x < l.size(); x++){
                    code.push_back('L');
                    ans++;
                } 
                break;
            } else {
                for(int x = j; x < r.size(); x++){
                    code.push_back('R');
                    ans++;
                }
                break;
            }
        }
    }
    // cout << i << " " << j << endl;
    if(flag){
        cout << ans << endl;
        for(int i = 0; i < code.size();i++){
            cout << code[i];
        }
        cout << "\n";
    } else if(i!= l.size()){
        // cout << "loz" << endl;
        while(i != l.size()){
            // cout << "buoi";
            code.push_back('L');
            ans++;
            i++;
        }
        cout << ans << endl;
        for(int i = 0; i < code.size();i++){
            cout << code[i];
        }
        cout << "\n";
    } else {
        // cout << "di";
        while(j != r.size()){
            code.push_back('R');
            ans++;
            j++;
        }
        cout << ans << endl;
        for(int i = 0; i < code.size();i++){
            cout << code[i];
        }
        cout << "\n";
    }
}

