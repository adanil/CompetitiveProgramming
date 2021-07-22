#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll minEl = -1;
    for (int i = 0;i < n;i++){
        ll el;
        cin >> el;
        a[i] = el;
    }

    sort(a.begin(),a.end());
    ll ans = 0;
    for (int i = 1;i < n;i++){
        ans += a[i] - a[i-1] - 1;
    }
    cout << ans << endl;
    return 0;
}