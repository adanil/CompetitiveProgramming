#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = -100000000000000;


int main() {
    ifstream fin("slalom.in");
    ofstream fout("slalom.out");

    ll n;
    fin >> n;
    vector<vector<ll>>mount(n);
    vector<vector<ll>>dp(n);
    for (int i = 0;i < n;i++){
        for (int j = 0;j < i + 1;j++){
            ll el;
            fin >> el;
            mount[i].push_back(el);
            dp[i].push_back(INF);
        }
    }
    dp[0][0] = mount[0][0];

    for (int i = 1;i < n;i++){
        for (int j = 0;j < dp[i].size();j++){
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + mount[i][j];
            else if (j  == i)
                dp[i][j] = dp[i - 1][j - 1] + mount[i][j];
            else{
                dp[i][j] = max(dp[i - 1][j - 1] + mount[i][j],dp[i - 1][j] + mount[i][j]);
            }
        }
    }
    fout << *max_element(dp[n - 1].begin(),dp[n-1].end()) << endl;




    return 0;
}