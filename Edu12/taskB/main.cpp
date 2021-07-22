#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;
    vector<int>things(k);
    for (int i = 0;i < k;i++){
        cin >> things[i];
    }

    vector<vector<int>> customer(n,vector<int>(m));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++)
            cin >> customer[i][j];
    }
    ll ans = 0;

    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            int tmp = customer[i][j];
            auto it = find(all(things),tmp);
            ans += it - things.begin() + 1;
            things.erase(it);
            things.insert(things.begin(),tmp);
        }
    }
    cout << ans << endl;
    return 0;
}