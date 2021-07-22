#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
using ll = long long;
const ll INF = 1000000000000000;

int main() {
    ifstream fin("king2.in");
    ofstream fout("king2.out");
    vector<vector<ll>>table(8,vector<ll>(8,0));
    for (int i = 0;i < 8;i++){
        for (int j = 0;j < 8;j++){
            fin >> table[i][j];
        }
    }
    vector<vector<ll>>dp(8,vector<ll>(8,INF));
    dp[7][0] = 0;
    for (int i = 7;i >= 0;i--){
        for (int j = 0;j < 8;j++){
            if (j > 0)
                dp[i][j] = min(dp[i][j],dp[i][j - 1] + table[i][j]);
            if (i < 7)
                dp[i][j] = min(dp[i][j],dp[i + 1][j] + table[i][j]);
            if (i < 7 && j > 0)
                dp[i][j] = min(dp[i][j],dp[i + 1][j - 1] + table[i][j]);
        }
    }
    fout << dp[0][7] << endl;
    return 0;
}