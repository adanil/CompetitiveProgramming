#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    ifstream fin("peacefulsets.in");
    ofstream fout("peacefulsets.out");
    fin.tie(NULL);
    fout.tie(NULL);
    ll n;
    fin >> n;
    vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
    for (int i = 1;i <= n;i++ )
        dp[i][i] = 1;
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            if (j > i)
                break;
            for (int k = 1;k <= j/2;k++){
                dp[i][j] += dp[i - j][k];
            }
        }
    }
    ll sum = 0;
    for (int i = 1;i <= n;i++){
        sum += dp[n][i];
    }
    fout << sum << endl;
    return 0;
}


