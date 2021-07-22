#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll>dp(n + 1);
    vector<ll> a(n + 1);
    dp[0] = 1;
    a[0] = 0;
    dp[1] = 3;
    a[1] = 1;
    for (int i = 2;i <= n;i++){
        dp[i] = dp[i - 1] * 3 - a[i - 1];
        a[i] = dp[i-1];
    }
    cout << dp[n] << endl;
    return 0;
}