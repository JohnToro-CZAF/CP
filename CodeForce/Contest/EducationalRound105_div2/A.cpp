#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

struct tuple {ll x; ll y; ll z;};

ll inf = LONG_MAX;

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

ll gcd(ll x, ll y){
	ll ans = x;
	ll temp = y;
	while(ans != temp){
		if(ans < temp){ 
			temp -= ans;
		} else{
			ans -= temp;
		}
	}
	return ans;
}

ll lcm(ll x, ll y){
	return x*y/gcd(x, y);
}

void solve(){
	string s;
	cin >> s;
	ll n = s.size();
	// cout << n;
	char a[8][n];
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[0][i] = '(';
		}
		if(s[i] == 'B'){
			a[0][i] = '(';
		}
		if(s[i] == 'C'){
			a[0][i] = '(';
		}
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[1][i] = '(';
		}
		if(s[i] == 'B'){
			a[1][i] = ')';
		}
		if(s[i] == 'C'){
			a[1][i] = '(';
		}
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[2][i] = '(';
		}
		if(s[i] == 'B'){
			a[2][i] = ')';
		}
		if(s[i] == 'C'){
			a[2][i] = ')';
		}
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[3][i] = '(';
		}
		if(s[i] == 'B'){
			a[3][i] = '(';
		}
		if(s[i] == 'C'){
			a[3][i] = ')';
		}
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[4][i] = ')';
		}
		if(s[i] == 'B'){
			a[4][i] = '(';
		}
		if(s[i] == 'C'){
			a[4][i] = '(';
		}
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[5][i] = ')';
		}
		if(s[i] == 'B'){
			a[5][i] = ')';
		}
		if(s[i] == 'C'){
			a[5][i] = '(';
		}
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[6][i] = ')';
		}
		if(s[i] == 'B'){
			a[6][i] = ')';
		}
		if(s[i] == 'C'){
			a[6][i] = ')';
		}
	}
	for(ll i = 0; i < n; i++){
		if(s[i] == 'A'){
			a[7][i] = ')';
		}
		if(s[i] == 'B'){
			a[7][i] = '(';
		}
		if(s[i] == 'C'){
			a[7][i] = ')';
		}
	}
	for(ll i = 0; i < 8; i++){
		bool chk = true;
		stack<char> v;
		for(ll j = 0; j < n; j++){
			// cout << a[i][j];
			if(a[i][j] == '('){
				v.push('(');
			} else {
				if(v.empty() || v.top() != '('){
					chk = false;
				} else {
					v.pop();
				}
			}
		}
		if(chk && v.empty()){
			puts("YES");
			return;
		}
		// cout << "\n";
	}
	cout << "NO" << endl;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}