#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>


using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<double>> p(n, vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double el;
            cin >> el;
            p[i][j] = el/100;
        }
    }

    for (int i = 0; i < n; i++) {
        sort(p[i].rbegin(), p[i].rend());
    }

    vector<double>best;

    for (int i = 0;i < m;i++)
        best.push_back(p[0][i]);

    sort(best.rbegin(),best.rend());
    if (best.size() > k){
        while (best.size() != k)
            best.erase(best.end()-1);
    }

//    for (auto el : best)
//        cout << el << ' ';
//    cout << endl;

    vector<double>bestLoc;

    for (int i = 1;i < n;i++){
        bestLoc.clear();
        for (int j = 0;j < m;j++){
            for (int q = 0;q < best.size();q++){
                bestLoc.push_back(p[i][j]*best[q]);
            }
        }
        best.clear();
        sort(bestLoc.rbegin(),bestLoc.rend());
        best = bestLoc;
        if (best.size() > k){
            while (best.size() != k)
                best.erase(best.end()-1);
        }

    }

    double ans = 0;
    for (auto el : best){
        ans += el;
    }
    cout << setprecision(7) << ans << endl;

    return 0;
}