#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    const ll mod = 1000000007;
    int n,k;
    cin >> n >> k;
    vector<vector<ll>>divs(n + 1);
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= i;j++){
            if (i % j == 0)
                divs[i].push_back(j);
        }
    }

    vector<vector<ll>>dp(k,vector<ll>(n + 1));
    for (int i = 1;i < n + 1;i++)
        dp[0][i] = 1;
    for (int i = 1;i < k;i++){
        for (int j = 1;j < n  + 1;j++){
            for (auto d : divs[j]) {
                dp[i][j] += dp[i - 1][d];
                dp[i][j] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1;i < n + 1;i++) {
        ans += dp[k - 1][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}