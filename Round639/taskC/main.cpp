#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        map<ll,int>ans;
        vector<ll>a(n*2);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
            a[i + n] = a[i];
        }
        bool fl = false;
        for (int i = 0;i < 2*n;i++){
            ++ans[i + a[i]];
            if (ans[i+ a[i]] > 1)
                fl = true;
        }
        if (fl)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

    }
    return 0;
}