#include <iostream>
#include <cmath>
#include <string>

using namespace std;

using ll = long long;

const ll modulo = 1e9 + 7;

ll binpow (ll a, ll n,ll modulo) {
    if (n == 0)
        return 1;
    if (n % 2 == 1)
        return (binpow (a, n-1,modulo) % modulo * a)%modulo;
    else {
        ll b = (binpow (a, n/2,modulo))%modulo;
        return (b * b)%modulo;
    }
}


int main() {
    ll n,m,k;
    cin >> n >> m >> k;
    ll ans = 0;
    if (n == k){
        ans = binpow(m,(k+1)/2,modulo);
    }
    else if (k == 1){
        ans = binpow(m,n,modulo);
    }
    else if (k > n){
        ans = binpow(m,n,modulo);
    }
    else if (k % 2 == 0){
        ans = m;
    }
    else
        ans = m*m;
    ans %= modulo;
    cout << ans << endl;
    return 0;
}
