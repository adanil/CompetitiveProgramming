#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll>a(n);
        vector<ll>res(n);
        ll ans = 0;
        for (int i = 0;i < n;i++){
            cin >> a[i];
            res[i] = a[i];
            ans = max(ans,res[i]);
        }

        for (int i = n - 1;i >= 0;i--){
            if (a[i] + i >= n)
                continue;
            else {
                res[i] += res[a[i] + i];
                ans = max(ans,res[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}