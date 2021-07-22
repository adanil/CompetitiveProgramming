#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

const ll mod = 1000000007;

vector<ll>fac(1000001);

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

ll C (ll n, ll k) {
    ll res = fac[n] * (pw(fac[k] * fac[n - k],mod - 2,mod));
    res %= mod;
    return res;

}


char x,y;

bool isGood(int q){
    string s = to_string(q);
    for (auto c : s)
        if (c != x && c != y)
            return false;
    return true;
}

int main() {
    fac[0] = 1;
    for (int i = 1;i < 1000001;i++)
        fac[i] = (fac[i - 1] * i) % mod;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a,b,n;
    cin >> a >> b >> n;
    if (a > b){
        swap(a,b);
    }
    x = '0' + a;
    y = '0' + b;
    ll diff = b - a;
    ll sum = b * n;
    ll ans = 0;
    if (isGood(sum))
        ans++;
    for (int i = 1;i <= n;i++){
//        cout << sum - diff * i << endl;
        if (isGood(sum - diff * i)){
            ans += C(n,i);
            ans %= mod;
        }
    }
    cout << ans << endl;

}