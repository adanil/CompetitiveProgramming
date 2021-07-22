#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;

long double pw(long double a, long double b,long double m){
    if (b == 0)
        return fmod(1,m);
    long double u;
    if (fmod(b,2) == 0){
        u = fmod(pw(a,b/2,m),m);
        u = fmod(u * u,m);

    }
    else{
        u = fmod(pw(a,b-1,m),m);
        u *= fmod(a,m);

        u = fmod(u,m);

    }
    //cout << u << endl;
    return u;

}

int main() {
    ll n;
    ll md = 1000000007;
    cin >> n;
    ll ans = 1;
    for (ll i = 1;i <= n;i++){
        ans = (ans * i) % md;
    }
    ans = (ans - pw(2,n-1,md));
    cout << ans << endl;
    return 0;
}