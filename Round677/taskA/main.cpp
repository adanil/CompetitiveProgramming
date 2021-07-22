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
        int x;
        cin >> x;
        int ans = 0;
        bool fl = false;
        for (int i = 1;i < 10;i++){
            for (int v = i;v < 10000;v = v * 10 + i){
                ans += to_string(v).size();
//                cout << v << endl;
                if (v == x) {
                    fl = true;
                    break;
                }
            }
            if (fl)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}