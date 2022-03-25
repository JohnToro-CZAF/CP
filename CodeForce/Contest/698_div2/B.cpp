#include<bits/stdc++.h>

using namespace std;

int main(){
    int c;
    cin >> c;
    vector<set<int > > v;
    for(int i = 1; i <= 9; i++){
        set<int> s;
        for(int j = 1; j <= 10; j++){
            int k = 0;
            while(i*j + 10*k < 10*i){
                s.insert(i*j + 10*k);
                k++;
            }
        }
        v.push_back(s);
    }
    while (c--)
    {
        int q, d;
        cin >> q >> d;
        long a[q];
        for(int i = 0 ; i< q; i++){
            long ai;
            cin >> ai;
            if(ai >= 10*d){
                cout << "YES" <<endl;
                continue;
            } else if(v[d-1].count(ai) == 0){
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;

            }
        }
        
    }
    
}
