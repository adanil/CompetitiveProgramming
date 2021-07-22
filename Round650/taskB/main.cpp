#include <iostream>
#include <vector>

using ll = long long;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>a(n);
        ll c = 0;
        ll nc = 0;
        for (ll i = 0;i < n;i++){
            cin >> a[i];
            if (i % 2 != a[i] % 2){
                if (i % 2 != 0)
                    nc++;
                else
                    c++;
            }
        }
        if (nc == c)
            cout << c << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}