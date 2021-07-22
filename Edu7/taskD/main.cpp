#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 100000000000;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    vector<ll>ans(2*n);

    int l1,l2,r1,r2;
    l1 = 0;
    r2 = 2*n - 1;

    vector<ll>dst(n);

    for (int i = 1;i <= n;i++){
        dst[i - 1] = n - i;
    }

    for (int i = 0;i < n-1;i += 2){
        l2 = l1 + dst[i];
        ans[l1] = i + 1;
        ans[l2] = i + 1;
        l1++;

        r1 = r2 - dst[i+1];
        ans[r1] = i + 2;
        ans[r2] = i + 2;
        r2--;
    }
    for (auto el : ans) {
        if (el == 0)
            cout << n << ' ';
        else {
            cout << el << ' ';
        }
    }

    return 0;
}