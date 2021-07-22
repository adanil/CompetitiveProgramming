#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;
using ll = long long;





vector<ll> phi(5000001);
void phi_1_to_n(ll n) {

    phi[0] = 0;
    phi[1] = 1;
    for (ll i = 2; i <= n; i++)
        phi[i] = i;

    for (ll i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (ll j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    phi_1_to_n(5000001);

    ll t;
    scanf("%lld", &t);

    while (t--){
        ll n;
        scanf("%lld", &n);
        ll answ;

        answ = n - 1 - phi[n];
        printf("%lld\n",answ);
    }



    return 0;
}