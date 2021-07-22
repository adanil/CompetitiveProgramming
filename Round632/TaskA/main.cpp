#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        vector<vector<bool>> table(n,vector<bool>(m,false));
        bool isBlack = false;
        int b = 0;
        int w = 0;
        if (m % 2 == 0){
            for (int i = 0;i < m;i++) {
                for (int j = 0; j < n; j++) {
                    if (!isBlack) {
                        table[j][i] = true;
                        b++;
                    } else {
                        table[j][i] = false;
                        w++;
                    }
                }
                if (!isBlack)
                    isBlack = true;
                else
                    isBlack = false;
            }
        }
        else{
            for (int i = 0;i < m - 1;i++) {
                for (int j = 0; j < n; j++) {
                    if (!isBlack) {
                        table[j][i] = true;
                        b++;
                    } else {
                        table[j][i] = false;
                        w++;
                    }
                }
                if (!isBlack)
                    isBlack = true;
                else
                    isBlack = false;
            }
            for (int i = 0;i < n;i++){
                if (!isBlack) {
                    table[i][m-1] = true;
                    isBlack = true;
                    b++;
                }
                else{
                    table[i][m-1] = false;
                    isBlack = false;
                    w++;
                }
            }
        }

        if (b != w+1){
            table[0][1] = true;
            b++;
        }

        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (table[i][j])
                    cout << 'B';
                else
                    cout << "W";
            }
            cout << endl;
        }
    }
    return 0;
}