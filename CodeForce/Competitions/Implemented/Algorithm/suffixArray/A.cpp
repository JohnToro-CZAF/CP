#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    s += '$';
    // starting point k = 0;
    vector<int> c(n+1);
    vector<int> p(n+1);
    vector<pair<char, int> > a(n+1);
    for(int i = 0; i <= n; i++){
        a[i] = {s[i], i};
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++){
        p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(a[i].first == a[i-1].first){
            c[p[i]] = c[p[i-1]];
        }
    }
    
}
