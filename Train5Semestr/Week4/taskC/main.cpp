#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long double;
using ull = unsigned long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ull n;
    cin >> n;
    vector<ull> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    sort(a.begin(), a.end());
    vector<ull> diff(n - 1);
    for (ull i = 0; i < n - 1; i++) {
        diff[i] = a[i + 1] - a[i];
    }
    sort(diff.begin(), diff.end());
//    set<ll> diffSet;
    vector<ull> prefSum(n - 1);
    for (ull i = 0; i < n - 1; i++) {
        if (i == 0) {
            prefSum[i] = diff[i];
        } else
            prefSum[i] = prefSum[i - 1] + diff[i];
    }
    ull q;
    cin >> q;
    for (ull i = 0; i < q; i++) {
        ull l, r;
        cin >> l >> r;
        ull len = r - l + 1;
        ull ans = n * len;
        ull cnt = lower_bound(diff.begin(), diff.end(), len) - diff.begin();
        if (cnt == 0)
            cout << (unsigned long long) ans << endl;
        else {
            ans -= cnt * len - prefSum[cnt - 1];
            cout << (unsigned long long) ans << endl;
        }
    }

    return 0;
}