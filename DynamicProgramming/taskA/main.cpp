#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ifstream fin("ladder.in");
    ofstream fout("ladder.out");
    ll n;
    fin >> n;
    vector<ll> lad(n);
    for (auto &el : lad){
        fin >> el;
    }
    vector<ll> dp(n);
    for (auto i = 0;i < n;i++){
        if (i > 1)
            dp[i] = max(lad[i] + dp[i-1],lad[i] + dp[i - 2]);
        else if (i == 1)
            dp[i] = max(lad[i],lad[i] + dp[i - 1]);
        else
            dp[i] = lad[i];
    }
    fout << dp[n - 1] << endl;
    return 0;
}