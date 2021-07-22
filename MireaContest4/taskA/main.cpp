#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n,m;
    cin >> n >> m;
    ll rw,cw,rb,cb;
    cin >> rw >> cw;
    cin >> rb >> cb;
    if (abs(n-rw) <= 2 and abs(m - cw) <= 2)
        cout << "NO" << endl;
    else if ((abs(n - rb) <= 2 and abs(m - cb) <= 2) and ((rb < 3) and (cb < 3)))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}