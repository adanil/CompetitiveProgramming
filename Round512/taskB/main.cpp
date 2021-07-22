#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n,d;
    cin >> n >> d;
    ll m;
    cin >> m;
    vector<vector<bool>> table;

    double k1,k2,k3,k4;
    for (int i = 0;i < m;i++){
        int x,y;
        cin >> x >> y;
        if ( -d + x <= y and y <= d + x and d - x <= y and y <= n + (n - d) - x )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}