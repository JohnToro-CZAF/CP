#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxn = 1e5 + 5, maxk = 450;
int a[maxn], dp[maxn][maxk];
int inf = 1e9 + 7;
ll pref[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
        }
        int k = 0;
        while (k * (k + 1) / 2 <= n) k++;
        for (int j = 0; j < k; ++j) {
            dp[n + 1][j] = -inf;
        }
        dp[n + 1][0] = inf;
        for (int i = n; i >= 1; --i) {
            for (int j = 0; j < k; ++j) {
                dp[i][j] = dp[i + 1][j];
                if (j && i + j - 1 <= n && pref[i + j - 1] - pref[i - 1] < dp[i + j][j - 1]) {
                    dp[i][j] = max(dp[i][j], (int)(pref[i + j - 1] - pref[i - 1]));
                }
            }
        }
        int ans = 0;
        for (int j = 0; j < k; ++j) {
            if (dp[1][j] > 0) ans = j;
        }
        cout << ans << '\n';
    }
    return 0;
}