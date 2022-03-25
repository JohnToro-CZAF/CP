#include<bits/stdc++.h>

using namespace std;

bool chk(int & n){
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0){
		return false;
		} 
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	bool p = chk(n);
	if(n < 2){
		cout << "NO";
		return 0;
	}
	if(p){
		cout << "YES";
	} else {
		cout << "NO";
	}
}