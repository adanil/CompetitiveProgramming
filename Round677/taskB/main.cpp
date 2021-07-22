#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;


int main() {
    ll t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for (auto &el : a)
            cin >> el;
        bool fl = false;
        int k = 0;
        ll ans = 0;
        for (int i = 0;i < n;i++){
            if (a[i] == 1 && !fl)
                fl = true;
            else if (a[i] == 1 && fl){
                ans += k;
                k = 0;
            }
            else if (a[i] == 0 && fl){
                k++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}