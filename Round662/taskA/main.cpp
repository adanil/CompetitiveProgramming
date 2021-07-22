#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
//    vector<ll>ans(10000);
//    ans[1] = 1;
//    ans[2] = 2;
//    ans[3] = 2;
//    ans[4] = 3;
//    for (int i = 5;i < 10000;i++) {
//        ans[i] = i % 2 != 0 ? ans[i - 1] : ans[i - 1] + 1;
//        cout << ans[i] << endl;
//    }

    while(t--){
        ll n;
        cin >> n;
        if (n % 2 != 0){
            cout << n/2 + 1 << endl;
        }
        else
            cout << n/2 + 1 << endl;
    }
    return 0;
}