#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        ll ans = 0;
        if (n == 1){
            cout << 0 << endl;
            continue;
        }
       if (n > 2)
           ans = m * 2;
       else
           ans = m;
       cout << ans << endl;
    }
    return 0;
}