#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        bool fl = true;
        int n;
        cin >> n;
        vector<ll>a(n);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
            if (i > 0)
                if (a[i - 1] <= a[i] )
                    fl = false;
        }
        if (!fl){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;

    }
    return 0;
}