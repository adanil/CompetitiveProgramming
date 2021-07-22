#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const ll modulo = 1e9 + 7;
static vector<ll>fac(5*1e5 + 1);
static vector<ll>invFac(5*1e5 + 1);

ll binpow(ll a,ll p){
    if (p == 0)
        return 1;
    if (p % 2 == 0) {
        ll tmp = binpow(a,p/2)%modulo;
        return (tmp*tmp)%modulo;
    }
    else
        return (binpow(a,p-1)%modulo * a)%modulo;
}

ll A(ll n,ll m){
    if (n > m)
        return fac[m];
    return (fac[m] * invFac[m - n])%modulo;
}

ll C(ll k,ll n){
    return ((fac[n] * invFac[k])%modulo * invFac[n - k])%modulo;
}

int main() {


    fac[0] = 1;
    for (int i = 1;i < fac.size();i++)
        fac[i] = (fac[i-1]*i)%modulo;
    invFac[5*1e5] = binpow(fac[5*1e5],modulo - 2);
    for (int i = 5*1e5 - 1;i >= 0;i--){
        invFac[i] = (invFac[i + 1] * (i+1))%modulo;
    }

    ll n,m;
    cin >> n >> m;

    ll all = A(n,m);
//    cout << all << endl;
    all = (all * all);
//    cout << all << endl;
//    if (all > 881613484)
//        cout << "ok" << endl;

    unsigned long long d = 0;

    for (ll i = 1;i <= n;i++){
        if (i % 2 != 0){
            d += (((C(i,n)*A(i,m))%modulo)*((A(n-i,m-i)*A(n-i,m-i))%modulo))%modulo;
        }
        else{
            d -= (((C(i,n)*A(i,m))%modulo)*((A(n-i,m-i)*A(n-i,m-i))%modulo))%modulo;
        }
//        cout << d << endl;
    }

    cout << (all - d)%modulo << endl;



    return 0;
}