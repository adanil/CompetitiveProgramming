#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n,k;
    cin >> n >> k;
    ll ans = 0;
    if (n*2 - 1 < k)
        cout << 0 << endl;
    else{
        ans = k % 2 == 0 ? k / 2 - 1 : k / 2;
        if (k > n) {
            ans -= (k - n) - 1;
        }
        cout << ans << endl;
    }
    return 0;
}