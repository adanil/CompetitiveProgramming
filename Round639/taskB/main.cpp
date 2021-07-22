#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    vector<ll>pyr;
    ll maxH = 100000;
    ll prev = 0;
    for (int i = 1;i < maxH;i++) {
        prev += 2 * i + (i - 1);
        pyr.push_back(prev);
    }
    while(t--){
        ll n;
        cin >> n;
        if (n == 1){
            cout << 0 << endl;

        }
        else {
            ll ans = 0;
            while(n > 1) {
                ans++;
                auto it = upper_bound(pyr.begin(), pyr.end(), n);
                n -= pyr[it - pyr.begin() - 1];
            }
            cout << ans << endl;
        }


    }
    return 0;
}