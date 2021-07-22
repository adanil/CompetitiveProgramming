#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll>a(n);
    bool havePositive = false;
    ll indPositive = -1;
    ll max;
    ll i = 0;
    for (auto &el : a) {
        cin >> el;
        if (i == 0) {
            max = el;
            indPositive = i;
        }
        else if (el > max){
            max = el;
            indPositive = i;
        }
        i++;
    }

    havePositive = true;
    ll ans = 0;
    if (havePositive)
        ans = a[indPositive];

    bool skipStep = false;

    ll sumRight = 0;

    ll sumLeft = 0;


    if (havePositive){
        if (n - 1 >= indPositive + 1) {
            sumRight = a[indPositive + 1];
            for (int i = indPositive + 2; i < n; i++) {
                if (sumRight < 0 && a[i] > 0) {
                    sumRight -= a[i];
                } else if (sumRight > 0 && a[i] < 0){
                    sumRight = a[i] - sumRight;
                }
                else if (sumRight < 0 && a[i] < 0) {
                    ans -= sumRight;
                    sumRight = a[i];
                } else if (sumRight < a[i])
                    sumRight -= a[i];
            }
        }
        ans -= sumRight;

        if (indPositive - 1 >= 0){
            sumLeft = a[indPositive - 1];
            for (int i = indPositive - 2;i >= 0;i--){
                if (sumLeft < 0 && a[i] > 0) {
                    sumLeft -= a[i];
                } else if (sumLeft > 0 && a[i] < 0){
                    sumLeft = a[i] - sumLeft;
                }
                else if (sumLeft < 0 && a[i] < 0) {
                    ans -= sumLeft;
                    sumLeft = a[i];
                } else if (sumLeft < a[i])
                    sumLeft -= a[i];
            }
        }

        ans -= sumLeft;
    }


    cout << ans << endl;

    return 0;
}