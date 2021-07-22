#include <iostream>

using ll = long long;
using namespace std;


ll gcd(ll a,ll b,ll &x,ll &y){
    if (a == 0){
        x = 0; y = 1;
        return b;
    }
    ll x1,y1;
    ll d = gcd(b%a,a,x1,y1);
    x = y1 - (b/a)*x1;
    y = x1;
    return d;
}

int main() {
    ll a,b,c;
    cin >> a >> b >> c;
    ll x,y;
    ll g = gcd(a,b,x,y);
    if (c % g != 0){
        cout << -1 << endl;
        return 0;
    }

    x *= c/g;
    y *= c/g;

    ll xcop = x;
    ll ycop = y;

    ll kxn = ((long long)-1000000 - xcop)*g/b;
    ll kyv = ((long long)10e8 - ycop) * -g/a;

    ll k = kxn;
    ll kxv = ((long long)10e10 - xcop)*g/b;
    ll kyn = ((long long)-10e10 - ycop) * -g/a;
    while ( x < -10e9  || x > 10e9 || y < -10e9  || y > 10e9 ){
        x = xcop + k*b/g;
        y = ycop - k*a/g;
        k += 1;
    }

    cout << 0 << endl;
    cout << x << ' ' << y << endl;

    return 0;
}