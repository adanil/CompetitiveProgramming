#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;



int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for (auto &el : a)
        cin >> el;

    sort(a.rbegin(),a.rend());
    ll mx = a[0];

    for (ll i = mx;i >= 1;i--){
        bool fl = true;
        for (int j = 0;j < n;j++){
            if (a[j] % i != 0){
                fl = false;
                break;
            }
        }
        if (fl){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}