#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0;i < n;i++){
            cin >> a[i];
        }
        ll ans = 0;
        bool isNegative = false;
        ll minNeg;
        ll maxPosit;
        if (a[0] < 0) {
            isNegative = true;
            minNeg = a[0];
        }
        else{
            maxPosit = a[0];
        }

        ll pnt = 0;
        while(pnt < n){
            if (isNegative && a[pnt] > 0){
                isNegative = false;
                ans += minNeg;
                maxPosit = a[pnt];
            }
            else if (isNegative && a[pnt] < 0){
                if (a[pnt] > minNeg)
                    minNeg = a[pnt];
            }
            else if(!isNegative && a[pnt] < 0){
                isNegative = true;
                ans += maxPosit;
                minNeg = a[pnt];
            }
            else if(!isNegative && a[pnt] > 0){
                if (a[pnt] > maxPosit)
                    maxPosit = a[pnt];
            }
            pnt++;
        }
        if (isNegative)
            ans += minNeg;
        else
            ans += maxPosit;
        cout << ans << endl;

    }
    return 0;
}