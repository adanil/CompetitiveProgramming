#include <iostream>

using namespace std;


int main() {
    int n,b,p;
    cin >> n >> b >> p;

    int ans = 0;
    int ans2 = p * n;
    while(n != 1) {
        int k = 1;
        while (k <= n) {
            k <<= 1;
        }
        k /= 2;
        ans += b * k + k/2;
        n = n - k / 2;
    }
    cout << ans <<' ' << ans2 <<  endl;

    return 0;
}