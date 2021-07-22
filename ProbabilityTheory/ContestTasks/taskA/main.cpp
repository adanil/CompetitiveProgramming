#include <iostream>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        if (b == 0){
            cout << 1 << endl;
            continue;
        }
        if (a == 0){
            cout << 0.5 << endl;
            continue;
        }
        double sall = 2*b * a;
        double starg = (double)(a*a)/8 + a*b;
        if ((double)a/4 > b){
            double minus  = ((double)a/4 - b)/2 * (double(a) - 4*b);
            starg -= minus;
        }
        double ans = starg/sall;
        cout << setprecision(7) << ans << endl;
    }
    return 0;
}