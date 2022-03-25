#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;

struct tuple {ll x; ll y; ll z;};

// ll inf = LONG_MAX;

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

void recur(int current, int size, int a[], vector<int> & v){
	if(size == 0){
		v.push_back(current);
		return;
	} else {
		for(ll i = 0; i < 5; i++){
			recur(current*10+a[i], size-1, a, v);
		}
	}
}

struct duo
{
	int x;
	int y;
};

int reflect(int t){
	int temp = t/10;
	int temp1 = t - temp*10;
	// cout << temp << " " << temp1 << endl;
	int donvi, chuc;
	if(temp != 2 && temp != 5) donvi = temp;
	if(temp == 2) donvi = 5;
	if(temp == 5) donvi = 2;
	if(temp1 != 2 && temp1 != 5) chuc = temp1;
	if(temp1 == 2) chuc = 5;
	if(temp1 == 5) chuc = 2;
	int tet = chuc*10+donvi;
	return tet;
}

void solve(){
	int h, m;
	cin >> h >> m;
	string in;
	int hour, minute;
	scanf("%02d:%02d", & hour, & minute);
	int must = hour*m + minute;
	int a[5] = {0, 1, 2, 5, 8};
	vector<int> v;
	vector<duo> v1;
	recur(0, 2, a, v);
	vector<int> v2;
	// cout << v.size();
	for(auto t : v){
		for(auto t1 : v){
			if((reflect(t) <= h-1 && reflect(t1) <= m-1) && (t1 <= h-1 && t <= m-1)){
				// cout << t1 << " " << t << endl;
				v2.push_back(t1*m+t);
			}
		}
	}
	ll inf = 10000000;
	sort(v2.begin(), v2.end());
	ll ans = inf;
	// cout << "\n";
	// cout << must << "heere" << endl;
	for(ll i = 0; i < v2.size(); i++){
		// cout << v2[i] << " "; 
		if(v2[i] >= must){
			ans = v2[i];
			break;
		}
	}
	if(ans == inf){
		ans = v2[0];
	}
	// cout << ans;
	int t1, t2;
	t1 = ans/m;
	t2 = ans - t1*m;
	if(t1 <= 9){
		cout << 0 << t1 << ":";
	} else {
		cout << t1 << ":";
	}
	if(t2 <= 9){
		cout << 0 << t2;
	} else {
		cout << t2;
	}
	cout << "\n";
	// for(ll i = 0; i < v.size(); i++){
	// 	// cout << v[i] << " ";
	// }
}

int main(){
    int c;
    cin >> c;
    // cout << reflect(5) << endl;
    while(c--){
        solve();
    }
}