#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("knight.in");
    ofstream fout("knight.out");
    ll n,m;
    fin >> n >> m;
    vector<vector<ll>>dp(n,vector<ll>(m));
    dp[0][0] = 1;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if (i > 1 && j >0)
                dp[i][j] += dp[i - 2][j - 1];
            if (i > 0 && j > 1)
                dp[i][j] += dp[i - 1][j - 2];
        }
    }
    fout << dp[n - 1][m - 1] << endl;
    return 0;
}