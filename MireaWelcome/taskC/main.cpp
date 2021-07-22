#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n,m;
    cin >> n >> m;
//    vector<vector<char>>a(n,vector<char>(n));
//    vector<vector<char>>b(m,vector<char>(m));
//    for (int i = 0;i < n;i++){
//        for (int j = 0;j < n;j++)
//            cin >> a[i][j];
//    }
//    for (int i = 0;i < m;i++){
//        for (int j = 0;j < m;j++)
//            cin >> b[i][j];
//    }

    vector<string>a(n);
    vector<string>b(m);
    for (int i = 0;i < n;i++)
        cin >> a[i];

    for (int i = 0;i < m;i++)
        cin >> b[i];


    for (int i = 0;i < n;i++){
        for (int j = 0;j <n;j++){
            if (j + m > n)
                continue;
            if (a[i].substr(j,m) == b[0]){
                bool fl = true;
                for (int k = 1;k < m;k++) {
                    if (i + k >= n){
                        fl = false;
                        break;
                    }
                    if (j + m > n) {
                        fl = false;
                        break;
                    }
                    if (a[i + k].substr(j, m) != b[k]) {
                        fl = false;
                        break;
                    }
                }
                if (fl){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}