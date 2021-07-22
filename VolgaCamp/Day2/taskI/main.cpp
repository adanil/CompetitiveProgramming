#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> price(n);
    for (auto &el : price)
        cin >> el;
    sort(price.begin(),price.end());
    ll sum = price[n - 1];
    ll ans = 1;
    for (int i = 0;i < n - 1;i++){
        if (sum - price[i] >= 0){
            sum -= price[i];
            ans++;
        }
        else
            break;
    }
    cout << ans << endl;
    return 0;
}