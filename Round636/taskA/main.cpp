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
        ll k = 2;
        ll kSum = 3;
        while (n % kSum != 0){
            k *= 2;
            kSum += k;
        }
        cout << n / kSum << endl;
    }

    return 0;
}