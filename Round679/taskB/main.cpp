#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>rows(n,vector<int>(m));
        map<int,set<int>>rw;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                cin >> rows[i][j];
                rw[i].insert(rows[i][j]);
            }
        }
        vector<vector<int>>cols(m,vector<int>(n));
        for (int i = 0;i < m;i++){
            for (int j = 0;j < n;j++){
                cin >> cols[i][j];
            }
            if (i == 0) {
                for (int q = 0; q < n; q++) {
                    int el = cols[i][q];
                    for (int p = 0; p < n; p++) {
                        if (rw[p].count(el)) {
                            ans[q] = rows[p];
                        }
                    }
                }
            }
        }

        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }


    }
    return 0;
}