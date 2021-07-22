#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<double>a(n);
    vector<double>sqsum(n);
    for (int i = 0;i < n;i++){
        cin >> a[i];
        if (i == 0)
            sqsum[i] = a[i]* a[i];
        else
            sqsum[i] = sqsum[i-1] + (a[i]*a[i]);
    }
    ll q;
    cin >> q;
    for (int i = 0;i < q;i++){
        ll l,r;
        cin >> l >> r;
        double ch;
        if(l > 0)
            ch = sqsum[r] - sqsum[l-1];
        else
            ch = sqsum[r];
        double zn = r-l + 1;
        double ans = sqrt(ch/zn);
        cout << fixed << setprecision(6) << ans << endl;

    }



    return 0;
}