#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cout << "Kiem tra tinh nguyen to, Hay nhap so can kiem tra: " << endl;
	cin >> n;
	bool chk = true;
	if(n == 1){
		cout << "So nay khong la so nguyen to" << endl;
		return;
	}
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
			chk = false;
			break;
		}
	}
	if(chk){
		cout << "So nay la so nguyen to" << endl;
	} else {
		cout << "So nay khong la so nguyen to" << endl;
	}
}

int main(){
	solve();
	return 0;
}