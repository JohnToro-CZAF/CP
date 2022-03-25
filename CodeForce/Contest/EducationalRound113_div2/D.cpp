#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
#define forn(i,n) for(int i=0;i<n;++i)
#define all(a) (a).begin(), (a).end()
const int maxn = 2e5 + 5;
const ll INF = 1e9;

int n,m,k;
vvi onx(maxn);
vvi ony(maxn);
vi x(maxn);
vi y(maxn);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        cin >> n >> m >> k;
        /////////////////////////
        for(int i = 0; i < n; i++){
            onx[i].clear();
        }
        for(int i = 0; i < m; i++){
            ony[i].clear();
        }

        x.resize(n, 0);
        y.resize(m, 0);
        ////////////////////////
        set<int> xoor;
        set<int> yoor;
        for(int i = 0; i < n; i++){
            cin >> x[i];
            xoor.insert(x[i]);
        }
        for(int i = 0; i < m; i++){
            cin >> y[i];
            yoor.insert(y[i]);
        }
        set<int> uniquex;
        set<int> uniquey;
        forn(i, k){
            int x1, y1;
            cin >> x1 >> y1;
            if(yoor.find(y1) != yoor.end() && xoor.find(x1) != xoor.end()) continue;
            int indexx = lower_bound(x.begin(), x.end(), x1) - x.begin();
            int indexy = lower_bound(y.begin(), y.end(), y1) - y.begin();
            if(xoor.find(x1) == xoor.end()){
                uniquex.insert(indexx);
                onx[indexx].push_back(indexy);
            } else {
                uniquey.insert(indexy);
                ony[indexy].push_back(indexx);
            }
        }
        ll pairOnX = 0;
        for(auto indexy : uniquey){
            sort(all(ony[indexy]));
            int l = int(ony[indexy].size());
            ony[indexy].push_back(0);
            ll res = 0;
            ll sqr = 0;
            // ony[indexy].erase(unique(ony[indexy].begin(), ony[indexy].end()), ony[indexy].end());
            // cout << indexy << " " << l << endl;
            for(int i = 0; i < l; i++){
                // cout << ony[indexy][i] << " ";
            }
            // cout << "\n";
            // cout << "\\\\\\\\\\\\\\\\\\";
            int it = 0;
            int cnt = 1;
            while(it < l){
                while(it < l && ony[indexy][it] == ony[indexy][it+1]){
                    cnt++;
                    it++;
                }
                res += cnt;
                sqr += cnt*cnt;
                cnt = 1;
                it++;
            }
            pairOnX += (res*res - sqr)/2;
        }
        ll pairOnY = 0;
        for(auto indexx : uniquex){
            sort(all(onx[indexx]));
            int l = int(onx[indexx].size());
            onx[indexx].push_back(0);
            ll res = 0;
            ll sqr = 0;
            int it = 0;
            int cnt = 1;
            for(int i = 0; i < l; i++){
                // cout << onx[indexx][i] << " ";
            }
            // cout << "\n";
            while(it < l){
                while(it < l && onx[indexx][it] == onx[indexx][it+1]){
                    cnt++;
                    it++;
                }
                res += cnt;
                sqr += cnt*cnt;
                cnt = 1;
                it++;
            }
            // onx[indexx].erase(unique(onx[indexx].begin(), onx[indexx].end()), onx[indexx].end());
            pairOnY += (res*res - sqr)/2;
        }
        cout << pairOnY+pairOnX << endl;
    }
}

