#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;


ll onLayer(ll numLayer){
    if (numLayer == 1)
        return 1;
    ll side = 1 + 2*(numLayer - 1);
    return side + side + (side-2)*2;
}

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        n *= n;
        ll ans = 0;
        ll steps = 0;
        ll layer = 1;
        while(n != 0){
            ll onL = onLayer(layer);
            ans += steps * onL;
            n -= onL;
            steps++;
            layer++;
        }
        cout << ans << endl;

    }
    return 0;
}