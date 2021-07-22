#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ifstream fin("lepus.in");
    ofstream fout("lepus.out");
    ll n;
    fin >> n;
    vector<char> table(n);
    for (auto &el : table)
        fin >> el;
    vector<ll>dp(n,-1);
    dp[0] = 0;
    for (ll i = 1;i < n;i++){
        if (table[i] == 'w')
            continue;
        else if (table[i] == '.'){
            if (i > 0) {
                if (dp[i - 1] > -1)
                    dp[i] = max(dp[i - 1], dp[i]);
            }
            if (i > 2) {
                if (dp[i - 3] > -1)
                    dp[i] = max(dp[i - 3], dp[i]);
            }
            if (i > 4) {
                if (dp[i - 5] > -1)
                    dp[i] = max(dp[i - 5], dp[i]);
            }
        }
        else{
            if (i > 0) {
                if (dp[i - 1] > -1)
                    dp[i] = max(dp[i - 1] + 1, dp[i]);
            }
            if (i > 2) {
                if (dp[i - 3] > -1)
                    dp[i] = max(dp[i - 3] + 1, dp[i]);
            }
            if (i > 4) {
                if (dp[i - 5] > -1)
                    dp[i] = max(dp[i - 5] + 1, dp[i]);
            }
        }
    }
    fout << dp[n - 1] << endl;
    return 0;
}