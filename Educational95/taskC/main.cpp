#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<int>a(n);
        for (int i = 0;i < n;i++){
            cin >> a[i];
        }
        ll ans = 0;
        ll state = 0;

        ll FIRSTONE = 0, FIRSTTWO = 1,SECONDONE = 2,SECONDTWO = 3;
        vector<vector<ll>>dp(n,vector<ll>(4,100000000000));
        dp[0][FIRSTONE] = a[0];
        for (int i = 1;i < n;i++){
           dp[i][FIRSTONE] = min(dp[i - 1][SECONDONE],dp[i - 1][SECONDTWO]) + a[i];
           dp[i][FIRSTTWO] = dp[i - 1][FIRSTONE] + a[i];
           dp[i][SECONDONE] = min(dp[i - 1][FIRSTONE],dp[i - 1][FIRSTTWO]);
           dp[i][SECONDTWO] = dp[i - 1][SECONDONE];
        }

        ans = 10000000000000;
        for (int i = 0;i < 4;i++){
            ans = min (ans,dp[n - 1][i]);
        }
        cout << ans << endl;
    }
    return 0;
}