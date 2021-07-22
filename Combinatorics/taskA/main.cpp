#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    const ll mod = 1000000007;
    cin >> n >> m;
    vector<string>names(n);
    vector<set<char>>chs(m);
    for (int i = 0;i < n;i++) {
        cin >> names[i];
        for (int j = 0;j < m;j++)
            chs[j].insert(names[i][j]);
    }
    ll ans = 1;
    for (auto const &s : chs) {
        ans *= s.size() % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}