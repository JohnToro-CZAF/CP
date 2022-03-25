#include<bits/stdc++.h>
#include<string>
#include<vector>

using namespace std;

void solve(long & n, int & k){
    vector<long> v;
    char a[k];
    string s;
    cin >> s;
    for(int i=0; i < k; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        bool isinA = false;
        for(int j = 0; i < k; j++){
            if(s[i] == a[j]){
                isinA = true;
            }
        }
        (isinA) ? v.push_back(1) : v.push_back(0);
    }
    vector<int> number;
    for(int i = 0; i < n; i++){
        int cur = 0;
        if(v[i] != 0){
            cur++;
        } else {
            number.push_back(cur);
            cur = 0;
        }
    }
    long sum = 0;
    for(int i = 0; i < number.size(); i++){
        sum += number[i]*(number[i]+1) / 2;
    }
    cout << sum;
}

int main(){
    long n;
    int k;
    cin >> n >> k;
    solve(n ,k);
}