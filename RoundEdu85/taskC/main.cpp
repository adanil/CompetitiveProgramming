#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;


int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> m(n);
        for (ll i = 0; i < n; i++) {
            cin >> m[i].first >> m[i].second;
        }
        vector<pair<ll, ll>> b = m;
        ll minInd = 0;
        ll minEl = m[0].first;
        ll minElSec = m[0].second;
        for (ll i = 1; i < n; i++) {
            if (m[i].first < minEl) {
                minEl = m[i].first;
                minInd = i;
                minElSec = m[i].second;
            } else if (m[i].first == minEl && m[i].second > minElSec) {
                minElSec = m[i].second;
                minEl = m[i].first;
                minInd = i;
            }
        }
        ll ans = 0;


        if (n == 1) {
            cout << m[0].first << endl;
        } else {
            b[0].first -= b[n - 1].second;
            b[0].first = max(0ll, b[0].first);
            ans += b[0].first;
            for (ll i = 1; i < n; i++) {
                b[i].first -= b[i - 1].second;
                b[i].first = max(0ll, b[i].first);
                ans += b[i].first;

            }

            ll nonZeroEl = -1;
            ll nonZeroElSec = -1;
            ll nonZeroElInd = -1;
            for (int i = 0; i < n; i++) {
                if (b[i].first != 0) {
                    if (nonZeroEl == -1) {
                        nonZeroEl = b[i].first;
                        nonZeroElSec = b[i].second;
                        nonZeroElInd = i;
                    } else {
                        if (b[i].first < nonZeroEl) {
                            nonZeroElSec = b[i].second;
                            nonZeroEl = b[i].first;
                            nonZeroElInd = i;
                        } else if (b[i].first == nonZeroEl) {
                            if (b[i].second > nonZeroElSec) {
                                nonZeroEl = b[i].first;
                                nonZeroElSec = b[i].second;
                                nonZeroElInd = i;
                            }

                        }
                    }
                }
            }

            ll ans1 = ans;

            ll ans2 = ans;
            bool fl = false;
            if (nonZeroEl != -1) {
                fl = true;
                if (nonZeroElInd == 0) {
                    ans1 += m[nonZeroElInd].first;
                    ans1 -= max(0ll, m[nonZeroElInd].first - m[n - 1].second);
                } else {
                    ans1 += m[nonZeroElInd].first;
                    ans1 -= max(0ll, m[nonZeroElInd].first - m[nonZeroElInd - 1].second);
                }
            }

            if (minInd == 0) {
                ans2 += m[minInd].first;
                ans2 -= max(0ll, m[minInd].first - m[n - 1].second);
            } else {
                ans2 += m[minInd].first;
                ans2 -= max(0ll, m[minInd].first - m[minInd - 1].second);
            }
            if (fl ==true)
                ans = min(ans1,ans2);
            else
                ans = ans2;
            cout << ans << endl;
        }


    }
    return 0;
}