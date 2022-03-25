#include<bits/stdc++.h>

#define f first
#define s second
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
using namespace std;


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

int cal(int x){
    int ans = 0;
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0){
            while(x % i == 0){
                ans++;
                x /= i;
            }
        }
    }
    if(x > 1) ans++;
    return ans;
}

int a,b,k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        cin >> a >> b >> k;
        int M = cal(a) + cal(b);
        int N;
        int g = gcd(a,b);
        if(a == b){
            N = 0;
        } else if(g == a || g == b) {
            N = 1;
        } else {
            N = 2;
        }
        if(N <= k && k <= M){
            if(N == 1 && k == 1){
                yes;
            } else if(k != 1){
                yes;
            } else {
                no;
            }
        } else {
            no;
        }
    }
}

