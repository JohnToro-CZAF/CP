#include<bits/stdc++.h>
using namespace std;

const int maxm = 1e5+12;
long long sum[maxm];
long long a[maxm];
const int mod = 1e9+7;

int main(){
	long long q,k;
	cin >> q >> k;
	a[0] = 0;
	for(long long i = 1; i <= maxm-1; i++){
		long long t = i/k;
		a[i] = (1+(i+1)*t-k*t*(t+1)/2)%mod;
	}
	long long s = 0;
	sum[0] = 0;
	for(long long i = 1; i <= maxm-1; i++){
		s += a[i];
		s%mod;
		sum[i] = s;
	}
	while(q--){
		long long l, r;
		cin >> l >> r;
		cout << "loz" << sum[l] << " " << sum[r] << endl;
		int ans = sum[r]-sum[l-1];
		ans %= mod;
		cout << ans << endl;
	}
	return 0;
}