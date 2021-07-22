#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;
using ll = long long;


map<ll,ll> factors(ll n){
    map<ll,ll> result;
    for (ll i = 2;i*i <= n;i++){
        while(n % i == 0){
            result[i]++;
            n /= i;
        }
    }
    if (n > 1)
        result[n]++;
    return result;
}


ll binpow(ll x,ll n){
    if (n == 0) return 1;
    long long u = binpow(x,n/2);
    u = u * u;
    if (n % 2 == 1)
        u = u * x;
    return u;
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



int main() {
    ifstream fin("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");
    ll a;
    fin >> a;
    ll n;

    auto mp = factors(a);
    ll tmp = 1;
    for (auto it = mp.begin();it != mp.end();it++){
        tmp *= it->first;
    }
    ll i = 1;

//    cout << binpow(tmp,tmp) << endl;
    while(pw(tmp*i,tmp*i,a) != 0)
        i++;
    fout << tmp * i << endl;

    return 0;
}