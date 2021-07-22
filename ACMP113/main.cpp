#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<vector<char>> table(n,vector<char>(n,0));

    for (long long i = 0;i < n;i++){
        for (long long j = 0;j < n;j++)
            cin >> table[i][j];
    }


    vector<vector<long long>> dp(n,vector<long long>(n,0));




    for(long long i = 0;i < n;i++) {
        for (long long j = n - 1; j >= 0; j--) {
            if (table[i][j] != '0'){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }


    long long ans = 0;
    if (n > 1){
        for (long long i = 1;i < n;i++){
            for (long long j = 1;j < n;j++){
                if (dp[i][j] == 0)
                    continue;
                vector<long long> thr;
                thr.push_back(dp[i-1][j]);
                thr.push_back(dp[i][j-1]);
                thr.push_back(dp[i-1][j-1]);
                dp[i][j] = *min_element(thr.begin(),thr.end()) + 1;
            }
        }


        for (long long i = 0;i < n;i++){
            for (long long j = 0;j < n;j++){
                if (dp[i][j] > ans)
                    ans = dp[i][j];
            }
        }
    }
    else{
        if (dp[0][0] == 1)
            ans = 1;
    }


    cout << ans*ans << endl;



    return 0;
}