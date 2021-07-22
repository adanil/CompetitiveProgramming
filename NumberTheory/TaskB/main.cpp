#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

using ll = long long;

long double pw(long double a, long double b,long double m );
ll pwl(ll a, ll b,ll m);
void generator();

int main() {
    long double a,b;
    long double m;
    //generator();
    cin >> a >> b >> m;
    cout << fixed << setprecision(0)<< pw(a,b,m) << endl;

    return 0;
}


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
ll pwl(ll a, ll b,ll m){
    //cout << b << endl;
    if (b == 0)
        return 1%m;
    ll u;
    u = pwl(a,b/2,m);
    u = (u * u)%m;
    if (b % 2 == 1)
        u = (u*a)%m;
    return u;

}


void generator(){
    for (ll a = 1;a < 1000000000;a++){
        for (ll b = 0;b < 1000000000;b++){
            for (ll m = 1;m < 100000000000;m++){
                ll ans1 = pwl(a,b,m);
                ll ans2 = pw(a,b,m);
                if (ans1 != ans2)
                    cout << "a: " << a << " b: " << b << " m: " <<
                    m << " ans: " <<ans1 << ' ' << ans2 << endl;
            }
        }
    }
}