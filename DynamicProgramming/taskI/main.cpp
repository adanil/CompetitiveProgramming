#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ifstream fin("knapsack.in");
    ofstream fout("knapsack.out");
    ll s,n;
    cin >> s >> n;
    vector<ll> w(n);
    for (auto &el : w)
        cin >> el;
    sort(w.begin(),w.end());
    vector<vector<ll>>dp(n + 1,vector<ll>(s + 1,0));
    for (int i = 0;i < s + 1;i++){
        dp[0][i] = 0;
    }
    for (int i = 0;i < n + 1;i++)
        dp[i][0] = 0;
    for (int i = 1;i < n + 1;i++){
        for (int j = 1;j < s + 1;j++){
            if (w[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - w[i - 1]] + w[i - 1]);
            else
                dp[i][j] = dp[i-1][j];

        }
    }
//    for (int i = 0;i < n + 1;i++){
//        for (int j = 0;j < s+1;j++){
//            cout << dp[i][j];
//        }
//        cout << endl;
//    }
    cout << dp[n][s] << endl;
    return 0;
}

