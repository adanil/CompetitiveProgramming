#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        ll fn = 0;
        for (int i = 2;i <= n;i++){
            if (n % i == 0){
                fn = i;
                break;
            }
        }
        if (fn %  2 != 0) {
            n += fn;
            fn = 2;
            k--;
        }
        cout << n + fn*k << endl;
    }
    return 0;
}