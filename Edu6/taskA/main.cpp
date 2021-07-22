#include <iostream>

using namespace std;
using ll = long long;
int main() {
    ll xs,ys,xt,yt;
    cin >> xs >> ys;
    cin >> xt >> yt;
    ll ans = 0;
    ans = max(abs(yt - ys),abs(xt - xs));
    cout << ans << endl;
    return 0;
}