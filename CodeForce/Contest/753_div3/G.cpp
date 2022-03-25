#include<bits/stdc++.h>
#include<limits.h>

#define f first
#define s second

using namespace std;
using ll = long long;
#define forn(i, n) for (int i = 0; i < int(n); i++)
typedef struct all {ll x; const void * y;} all;
typedef struct tuple{ll x; ll y; ll z; ll t; pair<ll, ll>p;} tuple;
ll inf = LONG_MAX;

ll cei(ll x, ll y){
    ll t = (x+y-1)/y;
    return t;
}

ll power(ll base, ll powerRaised)
{
    if (powerRaised != 0)
        return (base*power(base, powerRaised-1));
    else
        return 1;
}

ll findTheStriclyLessPower(ll base, ll n){
    if(n == 1){
        return 0;
    }
    ll temp = log(n)/log(base);
    if(power(base, temp) == n){
        return temp - 1;
    } else {
        return temp;
    }
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

int compairx(const void *x, const void *y){
    if(((all*)x)->x > ((all*)y)->x){
        return 1;
    } else {
        return 0;
    }
}

int compairy(const void *x, const void *y){
    if(((all*)x)->x > ((all*)y)->x){
        return 1;
    } else {
        return 0;
    }
}

void solve(){
    ll n;
    cin >> n;
    map <ll, vector<pair<ll, pair<ll, ll> > > > s;
    map <ll, vector<pair<ll, pair<ll, ll> > > >::iterator itr;
    vector<pair<ll, pair<ll, ll> > > vec;
    forn(i, n){
        ll bi;
        ll xi, yi, mi;
        cin >> xi >> yi >> mi;
        bi = xi+yi-mi;
        vector<pair<ll, pair<ll, ll> > > v;
        v.push_back((make_pair(i, make_pair(xi, yi))));
        s.insert(make_pair(bi, v));
    }
    for(itr = s.begin(); itr != s.end(); ++itr){
        vector<pair<ll, pair<ll, ll> > > v;
        ll bi;
        ll si = v.size();
        bi = itr->first;
        v = itr->second;
        all allx[si];
        all ally[si];
        tuple xy[si];
        forn(i, si){
            ll xi = v[i].second.first;
            ll yi = v[i].second.second;
            ll index = v[i].first;
            yi = xi+yi-bi-max(0ll, xi-bi);
            xi = max(0ll, xi - bi);
            xy[i].x = v[i].second.first;
            xy[i].y = v[i].second.second;
            xy[i].z = index;
            xy[i].z = 0;
            xy[i].z = 0;
            allx[i].x = xi;
            ally[i].x = yi;
            allx[i].y = xy+i;
            ally[i].y = xy+i;
        }
        qsort(allx, si ,sizeof(all), compairx);
        qsort(ally, si ,sizeof(all), compairy);
        forn(i, si){
            ((tuple*)ally[i].y)->t = 0;
        }
        ll i = 0, j = 0;
        while(j < si){
            if(((tuple*)ally[j].y)->t != 1){
                if(ally[j].x >= allx[i].x){
                    pair<ll, ll> yup;
                    yup.first = (((tuple*)allx[i].y)->p).first;
                    yup.second = (((tuple*)allx[i].y)->p).second;
                    ((tuple*)allx[i].y)->p = make_pair(abs(yup.first - ally[j].x), abs(yup.second - (bi - ally[j].x)));                    
                    ((tuple*)allx[i].y)->t = 1;
                    i++;
                }
            } else { 
                j++;
            }
        }
        forn(i, si){
            pair<ll, pair<ll, ll> > p;
            p.first = xy[i].z;
            p.second = xy[i].p;
            v[i] = p;
        vec.push_back(p);
        }
    }   
    sort(vec.begin(), vec.end());
    forn(i, vec.size()){
        cout << vec[i].second.first << " " << vec[i].second.second << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin >> c;
    while(c--){
        solve();
    }
}

