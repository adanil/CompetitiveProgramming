#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000000;


int main() {
    int n;
    cin >> n;
    vector<vector<int>>a(n,vector<int>(n,INF));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++)
            cin >> a[i][j];
    }
    vector<vector<int>>d(n,vector<int>(n,INF));
    d = a;
    for (int i = 0;i < n;i++){
        d[i][i] = 0;
    }
    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = min (d[i][j], d[i][k] + d[k][j]);

     for (int i = 0;i < n;i++){
         for (int j = 0;j < n;j++)
             cout << d[i][j] << ' ';
         cout << endl;
     }
    return 0;
}