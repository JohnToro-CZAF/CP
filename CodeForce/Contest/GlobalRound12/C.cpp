#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll x[template_size];
ll y[template_size];
ll z[template_size];

ll cei(ll a, ll b){
    ll t = (a+b-1)/b;
    return t;
}

void solve(){
    int n;
    int arr[5005];
    ll curr[5005];
    cin>>n;
    for(int x = 0; x < n; x++) cin>>arr[x];
    for(int x = 0; x < n; x++) curr[x]=0;
    
    ll ans=0;
    
    for(int x = 0; x < n; x++){
        ll temp=curr[x];
        
        if (temp<arr[x]-1){
            ans+=arr[x]-1-temp;
            temp+=arr[x]-1-temp;
        }
        
        curr[x+1]+=temp-arr[x]+1;
        if (x+2<n){ 
            for(int y = x+2; y < min(n, x+arr[x]+1); y++){
                curr[y]++;
            }
        }
    }
    
    cout<<ans<<endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}
