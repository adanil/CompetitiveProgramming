#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    for (int i = 0;i < t;i++){
        ll a,b;
        cin >> a >> b;
        if (a % b == 0)
            cout << 0 << endl;
        else{
            ll ans = 0;
            ans = (a/b + 1)*b - a;
            cout << ans << endl;
        }
    }
    return 0;
}