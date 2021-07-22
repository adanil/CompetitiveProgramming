#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ll n, s;
    cin >> n >> s;

    vector<ll> a(n);
//    if (s % 2 == 0) {
        ll k = s / 2;
        ll ones = n - 1;
        if (ones >= k) {
            cout << "NO" << endl;
            return 0;
        }
        ll mx = s - n + 1;
        a[0] = mx;
        for (int i = 1;i < n;i++)
            a[i] = 1;
        cout << "YES" << endl;
        for (int i = 0;i < n;i++)
            cout << a[i] << ' ';
        cout << endl << k << endl;

//    }

    return 0;
}