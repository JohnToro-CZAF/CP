#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

bool isPower(long long x, long long y) 
{ 
    if (x == 1) 
        return (y == 1); 
    long int pow = 1; 
    while (pow < y) 
        pow *= x;
    return (pow == y); 
} 
  
long long prevPowerofK(long long n, long long k)
{
    long long p = (long long)(log(n) / log(k));
    return p;
}
 
long long nextPowerOfK(long long n, long long k)
{
    return prevPowerofK(n, k) + 1;
}

void solve(){
    long long a, b;
    cin >> a >> b;
    vector<long long>v;
    if(a < b){
        cout << 1 << endl;
        return;
    }
    if(b == 1){
        v.push_back(INT_MAX);
    }
    else if(b == 1 && a == 1){
        cout << 2 << endl;
        // cout << "fuck";
    }
    else if(isPower(b,a) && b > 1){
        v.push_back(nextPowerOfK(a,b) + 1);
    }
    else {
        v.push_back(nextPowerOfK(a, b));
        //  cout << " ok";
    }
    long long  k = 1;
    while(k < 40){
        long long t = nextPowerOfK(a, b + k) + k;
        v.push_back(t);
        k++;
    }
    long long ans = INT_MAX;
    for(auto l : v){
        ans = min(ans, l);
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