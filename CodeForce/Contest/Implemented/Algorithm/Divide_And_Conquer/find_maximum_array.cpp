#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const ll template_size = 3000006;
const ll inf = 10000000006;
ll a[template_size];

struct triple {ll x;  ll y;  ll z;};

triple find_cross(ll arr[], ll low, ll high, ll mid){
	ll left, right;
	ll temp_sum_left = -inf;
	ll temp_sum = 0;
	for(ll i = mid; i >= low; i--){
		temp_sum += arr[i];
		if(temp_sum > temp_sum_left){
			temp_sum_left = temp_sum;
			left = i;
		}
	}
	ll temp_sum_right = -inf;
	temp_sum = 0;
	for(ll i = mid+1; i <= high; i++){
		temp_sum += a[i];
		if(temp_sum > temp_sum_right){
			temp_sum_right = temp_sum;
			right = i;
		}
	}
	return {left, right, temp_sum_left + temp_sum_right};
}

triple find(ll arr[], ll low, ll high){
	if(low == high){
		return {arr[low], low, high};
	} else {
		ll mid = (low+high)/2;
		triple left = find(arr, low, mid);
		triple right = find(arr, mid+1, high);
		triple cross = find_cross(arr, low, high, mid);
		if(left.z > right.z && left.z > cross.z){
			return {left.x, left.y, left.z};
		} else if(right.z > left.z && right.z > cross.z){
			return {right.x, right.y, right.z};
		} else {
			return {cross.x, cross.y, cross.z};
		}
	}
}

int main(){
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	triple ans = find(a, 0, n-1); 
	cout << ans.x+1 << " " << ans.y+1 << " " << ans.z;
}
