#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>>r(n,vector<int>(m,0));
    for (int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)
            cin >> r[i][j];
    }
    vector<vector<int>>b(n,vector<int>(m,0));
    for (int i = 0;i < n;i++){
        for(int j = 0;j < m;j++)
            cin >> b[i][j];
    }

    vector<vector<int>> dp(n,vector<int>(m,0));
    int q = 0;
    q = b[0][0] - r[0][0];
    dp[0][0] = q;
    for (int i = 1;i < n;i++)
        dp[i][0] = dp[i-1][0] + (b[i][0] - r[i][0]);
    for (int i = 1;i < m;i++)
        dp[0][i] = dp[0][i-1] + (r[0][i] - b[0][i]);
    for (int i = 1;i < n;i++){
        for (int j = 1;j < m;j++){
            q = 0;
            abs(dp[i-1][j] + b[i][j] - r[i][j]) < abs(dp[i][j-1] + r[i][j] - b[i][j]) ? q = dp[i-1][j] + b[i][j] - r[i][j] :
                    q = dp[i][j-1] + r[i][j] - b[i][j];
            dp[i][j] = q;
        }
    }
    int ans1 = dp[n-1][m-1];

    q = r[0][0] - b[0][0];
    dp[0][0] = q;
    for (int i = 1;i < n;i++)
        dp[i][0] = dp[i-1][0] + (b[i][0] - r[i][0]);
    for (int i = 1;i < m;i++)
        dp[0][i] = dp[0][i-1] + (r[0][i] - b[0][i]);
    for (int i = 1;i < n;i++){
        for (int j = 1;j < m;j++){
            q = 0;
            abs(dp[i-1][j] + b[i][j] - r[i][j]) < abs(dp[i][j-1] + r[i][j] - b[i][j]) ? q = dp[i-1][j] + b[i][j] - r[i][j] :
                    q = dp[i][j-1] + r[i][j] - b[i][j];
            dp[i][j] = q;
        }
    }

    int ans2 = dp[n-1][m-1];

    cout << min(abs(ans1),abs(ans2)) << endl;
    return 0;
}