#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll>pur(n);
    for (auto &el : pur) {
        cin >> el;
        sum += el;
    }

    vector<vector<ll>>dp(n,100000);
    for (int i = n;i >= 0;i--){
        dp[i][]
    }
    return 0;
}