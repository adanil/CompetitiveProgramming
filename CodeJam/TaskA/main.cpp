#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t;
    cin >> t;
    int q = t;
    while (t--){
        int n;
        cin >> n;
        int trace = 0;
        int nRows = 0;
        int nCol = 0;
        vector<vector<int>>mat(n,vector<int>(n));
        set<int>tmp;
        bool fl = false;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < n;j++) {
                cin >> mat[i][j];
                tmp.insert(mat[i][j]);
                if (i == j)
                    trace += mat[i][j];
            }
            if (tmp.size() != n)
                nRows++;
            tmp.clear();
        }


        for (int i = 0;i < n;i++){
            for (int j = 0;j < n;j++)
                tmp.insert(mat[j][i]);
            if (tmp.size() != n)
                nCol++;
            tmp.clear();
        }

        cout << "Case #" << q - t << ": " << trace << ' ' << nRows << ' ' << nCol << endl;

    }
    return 0;
}