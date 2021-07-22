#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (ll i = a;i <= b;i++){
        ll minY = c - i + 1;
        if (minY < b)
            minY = b;
        ll n = c - minY + 1;
        ll nL = (c + i) - (d+1);
        ll countDiff = 0;
        if (nL > 0){
            countDiff = nL;
        }
        ll count = ((i + minY + i + c) * n)/2 - n * c;
        ans += count - countDiff;
//        for (ll j = minY;j <= c;j++){
////            ll zMax = min(j + i,d+1);
////            ll count = zMax - c;
////            ans += count;
////        }
    }
    cout << ans << endl;
    return 0;
}