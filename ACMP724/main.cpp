#include <iostream>
#include <vector>
#include <algorithm>

#define INF  1000000000;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> table(n, vector<int>(m));
    vector<int> cntOfZero(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
            if (table[i][j] == 0)
                cntOfZero[i]++;
        }
    }
    for (int i = 0; i < n; i++)
        if (cntOfZero[i] == 0) {
            cout << "Impossible" << endl;
            return 0;
        }
    for (int i = 0; i < n; i++) {
        int indRow = 0;
        bool fl = false;
        int cmp = cntOfZero[0];
        for (int k = 0; k < cntOfZero.size(); k++)
            if (cntOfZero[k] < cmp) {
                cmp = cntOfZero[k];
                indRow = k;
            }
        cntOfZero[indRow] = INF;
        //cout << "IndRow: " << indRow << endl;
        int indForAdd = -1;
        int cntZeroInCol = 0;
        for (int j = 0; j < m; j++) {
            if (table[indRow][j] == 0 && find(ans.begin(), ans.end(), j) != ans.end())
                fl = true;
        }
        if (fl)
            continue;
        for (int j = 0; j < m; j++) {

            if (table[indRow][j] == 0 && find(ans.begin(), ans.end(), j) == ans.end()) {
                int t = 0;
                //cout << "j : " << j << endl;
                for (int q = 0; q < n; q++) {
                    if (table[q][j] == 0)
                        t++;
                }
                if (cntZeroInCol < t) {
                    cntZeroInCol = t;
                    indForAdd = j;
                }
                //cout << "indForAdd : " << indForAdd << endl;
            }
        }
        ans.push_back(indForAdd);


    }
    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;


    return 0;
}