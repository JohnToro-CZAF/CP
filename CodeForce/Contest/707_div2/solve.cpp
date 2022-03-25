#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cout << "Nhap so luong so can nhap n: " << endl;
	cin >> n;
	int a[n+3];
	long long sum = 0;
	for(int i = 0; i < n; i++){
		cout << "Nhap so nguyen thu " << i+1 << " : " << endl;
		cin >> a[i];
		sum += a[i];
	}
	cout << "Tong cua " << n << " so nguyen la: " << sum << endl;
}

int main(){
	solve();
	return 0;
}