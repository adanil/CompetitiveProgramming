#include <iostream>
#include <vector>

using namespace std;

long long  C (int n, int k) {
    long long res = 1;
    for (int i=1; i<=k; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    //cout << res << endl;
    return res;
}


int main() {

    int n;

    cin >> n;

   long long ans = 0;

    for (int i = 2;i <= n;i++){
        ans += C(n,i);
    }

    cout << ans << endl;

    return 0;
}