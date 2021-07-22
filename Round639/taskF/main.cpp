#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>>a(n);
    for (int i = 0;i < n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    ll ans = 0;
    sort(a.begin(),a.end(),[](auto a,auto b){return a.first > b.first;});
    vector<ll>b(n);
    for (ll i = 0;i < n;i++) {
        ll curr = round(sqrt((double)a[i].first/3.0));
        if (curr > a[i].first)
            curr = a[i].first;
        if (ans + curr < k) {
            ans += curr;
            b[a[i].second] += curr;
        }
        else if (ans >= k)
            break;
        else {
            ans = k;
            b[a[i].second] += k - ans;
        }
    }
    for (int i = 0;i < n;i++)
        cout << b[i] << ' ';
    return 0;
}