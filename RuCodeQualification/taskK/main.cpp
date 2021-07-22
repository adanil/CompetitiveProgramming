#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<double>>p(m,vector<double>(n));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            double el;
            cin >> el;
            p[j][i] = el;
        }
    }
    for (int i = 0;i < m;i++){
        sort(p[i].rbegin(),p[i].rend());
    }
    double ans = 0;
    for (int i = 0;i < n;i++){
        double curr = 1;
        for (int j = 0;j < m;j++){
            curr *= p[j][i];
        }
        ans += curr;
    }
    cout << setprecision(6) << fixed << ans << endl;
    return 0;
}