#include<bits/stdc++.h>
#include<random>
using namespace std;
const int maxn = 3e5;

vector<int> pos[maxn];

int main(){
	default_random_engine generator;
	int n,q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];; 
		pos[a[i]].push_back(i);
	}
	while(q--){
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		vector<pair<int, int> > candidate;
		int largest_freq = 0;
		for(int i = 0; i < 40; i++){
			int index = uniform_int_distribution<int>(l, r)(generator);
			int c = a[index];
			// calculate frequency in of specific number in a given range
			//	upperbound => return an iterator that point the first occurence of c
			// in the range (>= l)
			// lowerbound => return an iterator that point to the last occurence of c
			// in the range (<= r)
			// upper - lower => return the number of occurence of c in [l,r]
			int fre = upper_bound(pos[c].begin(), pos[c].end(), r) - lower_bound(pos[c].begin(), pos[c].end(), l);
			// upperbound runs in (O(log(n)))
			largest_freq = max(largest_freq, fre);
			candidate.push_back(make_pair(fre, c));
		}
		sort(candidate.rbegin(), candidate.rend());
		// this sort will a little bit pitfall (|q|log|q| time)
		// usually just find the largest frequency 
		// (O(40) = O(1))
		// cout << largest_freq << endl; 
		cout << candidate[0].second << " " << candidate[0].first << endl;
	}
}