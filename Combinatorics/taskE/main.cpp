#include <iostream>
#include <vector>

using namespace std;
using ll = long long;



ll sum(ll n){
    return (n*(n - 1))/2;
}

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

 // 10 8
int main() {
//    cout << sum(2) << ' ' << sum(4) << ' ' << sum(5) << endl;
    ll n,m;
    cin >> n >> m;
    ll mn,mx,md;
    mx = n - (m - 1);
    mn = n/m;
    md = n % m;
    ll ansMx = sum(mx);
    ll ansMn = 0;
    if (md == 0)
        ansMn = m * sum(mn);
    else{
       ll t = n/m + 1;
       ll k = 1,r;

       ll testAns = sum(n/m) * (m - md) + sum(t) * md;
//       while(n % m != 0){
//           t = n/m + 1;
//           n -= t;
//           m--;
//           ansMn += sum(t);
//       }
//
//       ansMn += sum(n/m) * m;
//       cout << testAns << endl;
        ansMn = testAns;
    }
    cout << ansMn << ' ' << ansMx << endl;



    ll testMax = 0;

    return 0;
}