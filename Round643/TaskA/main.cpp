#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

ll minDigit(ll n){
    ll res = n % 10;
    while (n/10 > 0){
        res = min(res,n%10);
        n /= 10;
    }
    res = min(res,n%10);
    return res;
}

ll maxDigit(ll n){
    ll res = n % 10;
    while (n/10 > 0){
        res = max(res,n%10);
        n /= 10;
    }
    res = max(res,n%10);
    return res;
}

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll start,k;
        cin >> start >> k;
        ll result = start;
        k--;
        while(k--){
            ll md = minDigit(result);
            ll mxd = maxDigit(result);
            if (md == 0 || mxd == 0)
                break;
            else
                result = result + md*mxd;

        }
        cout << result << endl;

    }
    return 0;
}