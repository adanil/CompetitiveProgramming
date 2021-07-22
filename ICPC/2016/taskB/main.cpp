#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}


ll INF = 1000000001;
int main() {
    ll l,r,w;
    cin >> l >> r >> w;

    ll nd = gcd(w,r);
    r = r/nd;
    w = w/nd;
    l = l/nd;
    if (l - w + 1 <= r - 1){
        cout << "DEADLOCK" << endl;
    } else
        cout << "OK" << endl;
    return 0;
}