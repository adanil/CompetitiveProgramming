#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>


using namespace std;

int main() {

    long long n,m;
    double ans;
    cin >> n >> m;

    if (n < m){
        cout << 0 << endl;
        return 0;
    }

    vector<double>curr(n+1,0);
    vector<double>prev(n+1,0);
    prev[0]= 1;
    for (int i = 1;i < n+1;i++){
        for (int j = 1;j < i + 1;j++){
            curr[j] = prev[j-1]*0.5 + prev[j+1] * 0.5;
            curr[0] = prev[1];
        }
        prev = curr;
    }

    cout << fixed<< setprecision(7) << curr[m] << endl;


    return 0;
}