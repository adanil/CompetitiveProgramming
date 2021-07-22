#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    //vector<vector<ll>>dp(n,vector<ll>(n,0));
    vector<ll> a(n);
    ll ans = 0;
    ll sum = 0;
    ll prev;
    for (int i = 0;i < n;i++){
        cin >> a[i];
        if (i == 0) {
            prev = a[i];
            if (prev != 0)
                ans++;
            else
                break;
        }
        else {

            prev = a[i] + prev;
            if (prev != 0)
                ans++;
            else
                break;
        }
    }
    for (int i = 1;i < n;i++){
        ll prev;
        for (int j = i;j < n;j++){
            if (i == j) {
                prev = a[j];
                if (prev != 0)
                    ans++;
                else
                    break;
            }
            else {
                prev += a[j];
                if (prev != 0)
                    ans++;
                else
                    break;
            }

        }

    }
    cout << ans << endl;


    return 0;
}