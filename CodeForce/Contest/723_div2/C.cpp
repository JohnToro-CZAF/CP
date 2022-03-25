#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 1e5 + 13;
int n;
string s;
vector<pair<ll, string> > rv;
int b[maxn];
string a = "ATON";
int mergesort(int a[], int left, int right);
int merge(int a[], int left, int mid, int right);
int inversions(int a[], int len) {
  int count;
  count = mergesort(a, 0, len - 1);
  return count;
}
int mergesort(int a[], int left, int right) {
  int count = 0;
  if (left < right) {
     int mid = (left + right) / 2;
     count += mergesort(a, left, mid);
     count += mergesort(a, mid + 1, right);
     count += merge(a, left, mid, right);
     return count;
  }
  return count;
}

int merge(int a[], int left, int mid, int right) {
  int i = left;
  int j = mid + 1;
  int k = 0;
  int count = 0;
  int b[right - left + 1];
  while (i <= mid && j <= right) {
     if (a[i] <= a[j]) {
       b[k++] = a[i++];
     } else {
       count += (mid - i + 1);
       b[k++] = a[j++];
     }
  }
  while (i <= mid)
    b[k++] = a[i++];
  while (j <= right)
    b[k++] = a[j++];
  for (i = left, k = 0; i <= right; i++, k++) {
    a[i] = b[k];
  }
  return count;
}

void permute(string str, string out)
{
    if (str.size() == 0)
    {
        rv.push_back(make_pair(0, out));
        return;
    }
    for (int i = 0; i < str.size(); i++)
    {
        permute(str.substr(1), out + str[0]);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        cin >> s;
        n = s.length();
        map<char, int> fech;
        for(int i = 0; i < n; i++){
            fech[s[i]]++;
        }
        ll ans = 0;
        permute("ATON", "");
        for(int i = 0; i < rv.size(); i++){
            map<char, int> f;
            for(int j = 0; j < 4; j++){
                f[rv[i].second[j]] = j;
            }
            for(int i = 0; i < n; i++){
                b[i] = f[s[i]];
            }
            ll c = inversions(b, n);
            rv[i].first = c;
        }
        for(int i = 0; i < rv.size(); i++){
            int sumtemp = n;
            ll maxamount = 0;
            for(int j = 3; j >=0; j--){
                maxamount += (sumtemp-fech[a[j]])*fech[a[j]];
                sumtemp -= fech[a[j]];
            }
            ans = max(ans, maxamount - rv[i].first);
            rv[i].first = maxamount - rv[i].first;
        }
        string temp;
        for(auto &x : rv){
            if(x.first == ans){
                for(int i = 3; i >= 0; i--){
                    for(int j = 0; j < fech[x.second[i]]; j++){
                        cout << x.second[i];
                    }
                }
                cout << "\n";
                break;
            }
        }


    }
}

