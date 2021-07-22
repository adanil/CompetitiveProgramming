#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        ll ans = 0;
        vector<vector<char>>table(n,vector<char>(m));
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++)
                cin >> table[i][j];
        }
        for (int i = 0;i < n;i++){
            if (table[i][m - 1] != 'D' && table[i][m - 1] != 'C')
                ans++;
        }
        for (int i = 0;i < m;i++){
            if (table[n - 1][i] != 'R' && table[n - 1][i] != 'C')
                ans++;
        }
        cout << ans << endl;

    }
    return 0;
}