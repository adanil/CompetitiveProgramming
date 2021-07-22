#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1000000000;


int main() {
    int n;
    cin >> n;
    vector<vector<int>>a(n,vector<int>(n,INF));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++) {
            int el;
            cin >> el;
//            if (el == -1)
//                el = 0;
            a[i][j] = el;
        }
    }


//    for (int i = 0;i < n;i++){
//        for (int j = 0;j < n;j++) {
//            cout << a[i][j] << ' ';
//            //diametr = max(diametr, d[i][j]);
//        }
//        cout << endl;
//        //eksc[i] = *max_element(d[i].begin(),d[i].end());
//    }
//    cout << endl << endl;

    vector<vector<int>>d(n,vector<int>(n,INF));
    d = a;
    for (int i = 0;i < n;i++){
        d[i][i] = 0;
    }
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j) {
                if (i == j)
                    continue;
                if (d[i][k] < INF && d[k][j] < INF) {
                    if (d[i][k] == -1 || d[k][j] == -1)
                        continue;
                    if (d[i][j] < 0)
                        d[i][j] = d[i][k] + d[k][j];
                    else
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }

    int diametr = 0;
    vector<int> eksc(n);
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++) {
            //cout << d[i][j] << ' ';
            diametr = max(diametr, d[i][j]);
        }
        //cout << endl;
        eksc[i] = *max_element(d[i].begin(),d[i].end());
    }
    int rad = *min_element(eksc.begin(),eksc.end());
    cout << diametr << endl << rad << endl;
    return 0;
}