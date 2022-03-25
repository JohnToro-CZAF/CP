#include <bits/stdc++.h>
using namespace std;

int write(int j, int mod, int n){
    cout.put('?');
    for(int i = 1; i <= n; i++){
        if(i == j){
            cout << " " << mod;
        } else {
            cout << " " << ((mod == 2) ? 1 : 2);
        }
    }
    cout << "\n" << std::flush;
    int k;
    cin >> k;
    return k;
}


int main(){
    int n;
    cin >> n;
    int nex[n+9];
    int c[n+9];
    memset(nex, 0, sizeof(nex)); 
    memset(c, 0, sizeof(c));
    set<int> s;
    for(int i = 1; i <= n; i++){
        int k = write(i, 2, n);
        if(k > 0 && k != i){
            nex[i] = k;
        }
        int k1 = write(i, 1, n);
        if(k1 > 0 && k1 != i){
            nex[k1] = i;
        }
    }
    int index = 1;
    for(int i = 1; i <= n; i++){
        s.insert(nex[i]);
    }
    for(int i = 1; i <= n; i++){
        if(s.find(i) == s.end()){
            index = i;
        }
    }
    for(int i = 1; i <= n; i++){
        c[index] = i;
        index = nex[index];

    }
    cout.put('!');
    for(int i = 1; i <= n; i++){
        cout << " " << c[i];
    }
    cout << "\n" << std::flush;
    return 0;
}

