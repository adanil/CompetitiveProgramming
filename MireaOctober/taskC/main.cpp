#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    for (int n = 0;n < 1000;n++) {
        ll ans = 0;
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= n; y++) {
                if (x * y + x + y == n) {
                    ans++;
                    cout << x << ' ' << y << endl;
                }
            }
        }
        cout <<"ans " <<  ans << endl;
//        if (ans > 5)
    }

    return 0;
}




//#include <iostream>
//
//using namespace std;
//using ll = long long;
//
//bool check(int x,int y,int n) {
//
//    if (x*y + x + y == n)
//        return true;
//    else
//        return false;
//}
//
//int main() {
//    ll n;
//    cin >> n;
//    ll ans = 0;
//
//    if (check(0,n,n))
//        ans += 2;
//    if (check(1,2,n))
//        ans += 2;
//    if (check(2,2,n))
//        ans++;
//    cout << ans << endl;
//    return 0;
//}