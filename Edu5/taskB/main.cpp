#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
const ll INF = 100000000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<vector<ll>>cost(n,vector<ll>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    ll ans = -1;
    for (int i = 0;i < n;i++){
        ll currMin = cost[i][0];
        for (int j = 1;j < m;j++)
            currMin = min(currMin,cost[i][j]);
        ans = max (ans,currMin);
    }
    cout << ans << endl;
    return 0;
}