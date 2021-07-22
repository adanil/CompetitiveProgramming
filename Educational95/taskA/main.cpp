#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll x,y,k;
        cin >> x >> y >> k;

        x--;
        ll needPalk = y * k + k;
        needPalk--;

        ll ans = 0;
        if (needPalk % x == 0)
            ans = needPalk/x;
        else
            ans = needPalk/x + 1;

        ans += k;
        cout << ans << endl;
    }
    return 0;
}