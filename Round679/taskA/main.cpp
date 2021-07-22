#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for (auto &el : a)
            cin >> el;
        vector<int>ans(n);
        for (int i = 0;i < n;i += 2){
            int b1= -101,b2 = -101;
            for (int q = -100;q <= 100;q++){
                if (q == 0)
                    continue;
                if ((a[i + 1] * q)% a[i] == 0 && abs((a[i + 1] * q)/ a[i]) <= 100){
                    b2 = q;
                    b1 = -(a[i + 1] * q)/ a[i];
                    if (abs(b1) <= 100)
                        break;
                }
            }
            ans[i] = b1;
            ans[i + 1] = b2;
        }
        for (auto &el : ans)
            cout << el << ' ';
        cout << endl;
    }
    return 0;
}