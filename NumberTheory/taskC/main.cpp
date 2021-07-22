#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

using ll = long long;

ll pw(ll a, ll n, ll m);

ll mul(ll a,ll b,ll m);

int main() {
    ll anspl = 0;
    ll ansmin = 0;
    ll ans = 0;

    ll n,k;
    ll p;
    ll testAns = 0;
    cin >> n >> p >> k;
    ll q;
    q = (ll)pow(10,16);
    bool plus = false,minus = false;
    for (ll i = 1;i <= n;i++){
        if ((n - i)%2 == 0) {
            testAns +=  pw(i%q, p, q) % q;
            anspl += pw(i%q, p, q);
            anspl = (anspl%q);

        }
        else {
            testAns -=  pw(i%q, p, q) % q;
            ansmin +=pw(i, p, q);
            ansmin = (ansmin%q);
        }
    }
    ll modulo = (ll)pow(10,k);
    ans = (anspl - ansmin)%modulo;

    cout << fixed << setprecision(0)<< testAns%modulo << endl;

    return 0;
}



ll pw(ll x, ll n, ll m) {
    if (n == 0) return 1%m;
    long long u = pw(x,n/2,m);
    u = (mul(u,u,m))%m;
    if (n%2 == 1) u = (mul(u,x,m))%m;
    return u;
}


ll mul(ll a,ll b,ll m){
    if (!a || !b) return 0;
    if (b == 1) return a;
    if (a == 1) return b;
    if (b % 2 == 0){
        ll t = mul(a,b/2,m)%m;
        return (2*t)%m;
    }
    ll t = mul(a,b-1,m)%m;
    return (t + a)%m;
}