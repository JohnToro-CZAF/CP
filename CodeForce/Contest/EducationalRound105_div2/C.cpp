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


void displaySubset(int subSet[], int size, vector<vector<int> > & v) {
   vector<int> temp;
   for(int i = 0; i < size; i++) {
	   	temp.push_back(subSet[i]);
   }
   v.push_back(temp);
}

void subsetSum(int set[], int subSet[], int n, int subSize, int total, int nodeCount ,int sum, vector<vector<int> > & v) {
   if( total == sum) {
      displaySubset(subSet, subSize, v);     //print the subset
      subsetSum(set,subSet,n,subSize-1,total-set[nodeCount],nodeCount+1,sum, v);     //for other subsets
      return;
   }else {
      for( int i = nodeCount; i < n; i++ ) {     //find node along breadth
         subSet[subSize] = set[i];
         subsetSum(set,subSet,n,subSize+1,total+set[i],i+1,sum, v);     //do for next node in depth
      }
   }
}

void findSubset(int set[], int size, int sum, vector<vector<int> > & v) {
   int *subSet = new int[size];     //create subset array to pass parameter of subsetSum
   subsetSum(set, subSet, size, 0, 0, 0, sum, v);
   delete[] subSet;
}

void solve(){
	vector<vector<int> > v;
	int n, k;
   cin >> n >> k;
   int weights[n];
   for(int i = 0; i < n; i++){
   		weights[i] = i+1;
   }
   findSubset(weights, n, k, v);
   int ans = 1000000;
   for(int i = 0; i < v.size(); i++){
   		int s = v[i].size();
   		ans = min(ans, s);
   }
   if(ans == 0){
   		for(int i = 0; i < n; i++){
   			cout << i << " "; 
   		}
   		cout << "\n";
   		return;
   } else {
   		for(int i = 0; i < v.size(); i++){
   			if(v[i].size() == ans){
   				for(int j = 0; j < v[i].size(); j++){
   					cout << v[i][j] << " ";
   				}
   				cout << "\n";
   			}
   			return;
   		}
   }
}

int main() {
	int c;
	cin >> c;
	while(c--){
		solve();	
	}
}