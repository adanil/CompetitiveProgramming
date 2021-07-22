#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll curS = 0;
    ll maxI = 0;
    for (ll i = 1;i < 1e7 * 2;i++){
        ll tmp = 1ll* i*(i + 1)/2ll;
        if (tmp <= n){
            curS = tmp;
            maxI = i;
        }
        else
            break;
    }
    if (n - curS == 0)
        cout << maxI << endl;
    else {
        cout << n - curS << endl;
    }
    return 0;
}