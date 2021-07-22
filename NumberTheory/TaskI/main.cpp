#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using ll =  long long;

int main() {
    ll n;
    cin >> n;
    ll ans = 0;
    ll i = 1;
    while (i*i <= n){
        if (i * i <= n)
            ans++;
        i++;
    }
    cout << ans << endl;



    return 0;
}