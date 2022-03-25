#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

ll inf = LONG_MAX;
const ll template_size = 300006;
vector<ll> v(template_size); 
ll a[template_size];
ll b[template_size];
ll c[template_size];

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

void solve(){
	ll n1, n2, hcf, lcm, temp;
	string s1, s2;
	cin >> s1 >> s2;
	n1 = s1.size();
	n2 = s2.size();
	hcf = n1;
    temp = n2;
    while(hcf != temp)
    {
        if(hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }
    lcm = (n1 * n2) / hcf;
    string t1(lcm, 'a'), t2(lcm, 'a');
    // cout << lcm;
    for(ll i = 0; i < lcm; i++){
    	t1[i] = s1[i%n1];
    	t2[i] = s2[i%n2];
    }
    for(ll i = 0; i < lcm; i++){
    	if(t1[i] != t2[i]){
    		cout << -1 << endl;
    		return;
    	}
    }
    for(ll i = 0; i < lcm; i++){
    	cout << t1[i];
    }
    cout << "\n";
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}