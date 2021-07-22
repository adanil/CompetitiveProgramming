#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    ll ans = 0;
    ll modulo = 1000000007;

    vector<vector<ll>>dp(s.size(),vector<ll>(s.size()/2+2,0));

    dp[0][0] = 1;


    ll bal = 0;
    for (ll i = 1;i < s.size();i++){
        for (ll j = 0;j < s.size()/2 + 1;j++){
            if (i == 0 && j == 0)
                continue;
            if (j == 0)
                dp[i][j] = dp[i-1][j+1];
            else
                dp[i][j] = (dp[i - 1][j-1] + dp[i-1][j+1])%modulo;
        }
    }

    for (ll i = 0;i < s.size();i++){
        if (s[i] == '(')
            bal++;
        else{
            ans += (dp[s.size() - i - 1][bal + 1])%modulo;
            ans %= modulo;
            bal--;
        }
    }
    cout << (ans + 1)%modulo << endl;



    return 0;
}