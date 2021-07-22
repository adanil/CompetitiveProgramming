#include <iostream>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ll n,k;
    cin >> n >> k;
    ll catalans[21] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420};
    vector<vector<ll>>dp(n * 2 + 1,vector<ll>(n + 1,0));

    dp[0][0] = 1;


    ll bal = 0;
    for (int i=0; i<n*2; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (j + 1 <= n)
                dp[i + 1][j + 1] = dp[i + 1][j + 1] + dp[i][j];
            if (j > 0)
                dp[i + 1][j - 1] = dp[i + 1][j - 1] + dp[i][j];
        }
    }

    string ans;
    ll i = 0;
    while (i < 2 * n){
        if (dp[i + 1][bal + 1] >= k) {
            ans += '(';
            bal++;
            i++;
        }
        else {
            k -= dp[i + 1][bal + 1];
            ans += ')';
            bal--;
        }
    }
    cout << ans << endl;

    return 0;
}