#include<bits/stdc++.h>
using namespace std;

const long long maxm = 1e5+12;
long long sum[maxm];
long long a[maxm];
const long long mod = 1e9+7;

int main(){
	long long q,k;
	cin >> q >> k;
	a[0] = 1;
	for(long long i = 1; i <= maxm-1; i++){
		a[i] = a[i-1] + ((i >= k) ? a[i-k] : 0);
		a[i] %= mod;
	}
	long long s = 0;
	sum[0] = 0;
	for(long long i = 1; i <= maxm-1; i++){
		s += a[i];
		sum[i] = s;
	}
	while(q--){
		long long l, r;
		cin >> l >> r;
		int ans = (sum[r]-sum[l-1])%mod;
		cout << ans << endl;
	}
	return 0;
}