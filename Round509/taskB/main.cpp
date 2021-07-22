#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap (a, b);
    }
    return a;
}

int main() {
    ll w,h,x,y;
    cin >> w >> h >> x >> y;

    ll dv = gcd(x,y);
    x /= dv;
    y /= dv;

    ll ans = min(w/x,h/y);
    cout << ans << endl;




    return 0;
}