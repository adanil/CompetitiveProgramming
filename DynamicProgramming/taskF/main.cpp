#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

const ll INF = 1000000000000000;

int main() {
    vector<ll>dp(300001,INF);
    ll s = 1;
    ll curr = 1;
    ll iter = 2;
    vector<ll>pyr;

    pyr.push_back(curr);
    dp[curr] = 1;
    while (s <= 300000){
       curr = (iter * (iter + 1))/2;
       s += curr;
       if (s > 300000)
           break;
       pyr.push_back(s);
       dp[s] = 1;
       iter++;
    }


    for (int i = 1;i < 300001;i++){
        for (int j = 0;j < pyr.size();j++){
            if (pyr[j] > i)
                break;
            dp[i] = min(dp[i],dp[i - pyr[j]] + 1);
        }
    }

    int t;
    cin >> t;
    while(t--){
        ll m;
        cin >> m;
        cout << dp[m] << endl;
    }
    return 0;
}