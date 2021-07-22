#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <string>



using namespace std;



using ld = long double;
using ll = unsigned long long;

const ld maxPw = 10e19;


ll phi (ll n);
long double pw(long double a, long double b,long double m);
ll pow(ll a, ll n, ll m);
int main() {
    ll a,b,c;
    ll m;
    cin >> a >> b >> c >> m;



    ll euler = phi(m);
    cout << "Euler func: " << euler << endl;
    ll pwMod =  pow((b%euler),c,euler);
    ll ans = pow((a%m),pwMod,m);
    cout << fixed << setprecision(0) << ans << endl;

    return 0;
}
//274545139392


ll pow(ll a, ll n, ll m) {
    ll r = 1 % m;
    while (n > 0) {
        if (n & 1) {
            r = (1LL * r * a % m);
        }
        a = (1LL * a * a % m);
        n >>= 1;
    }
    return r;
}



ll phi (ll n) {
    ll result = n;
    for (ll i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    if (n > 1)
        result -= result / n;
    return result;
}

