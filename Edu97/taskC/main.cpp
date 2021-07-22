#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using ll = long long;
using namespace std;
const int sf = 300;
const int inf = 100000000;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        vector<ll>t(n);
        set<ll>st;
        for (auto &el : t) {
            cin >> el;
            --el;
        }
        vector<int>free(n + 2*sf,0);
        ll ans = 0;
        for (int i = 0;i <= sf;i++){
            free[i] = inf;
        }

        sort(t.begin(),t.end());
        vector<vector<ll>> dp(n + 1, vector<ll>(2 * n, INF));
        dp[0][0] = 0;
        for(int i = 0;i < n + 1;i++)
            for(int j = 0;j < 2 * n - 1;j++) if (dp[i][j] < INF){
            if (i < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(t[i] - j));
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
        for (int j = 0;j < 2*n-1;j++){
            for (int i = 0;i < n + 1;i++)
                cout << dp[i][j]  << ' ';
            cout << endl;
        }
    }
    return 0;
}