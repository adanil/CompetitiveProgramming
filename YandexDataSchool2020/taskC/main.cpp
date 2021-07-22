#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;
map<ll,ll> result;

void factors(ll n){
    for (int i = 2;i*i <= n;i++){
        ll alpha = 0;
        while(n % i == 0){
            alpha++;
            n /= i;
        }
        if (alpha > 0)
            result[i] += alpha;
    }
    if (n > 1)
        result[n] += 1;
}

void factors2(ll n){
    for (int i = 2;i*i <= n;i++){
        ll alpha = 0;
        while(n % i == 0){
            alpha++;
            n /= i;
        }
        if (alpha > 0)
            result[i] -= alpha;
    }
    if (n > 1)
        result[n] -= 1;
}

ll pwl(ll a, ll b,ll m){
    if (b == 0)
        return 1%m;
    ll u;
    u = pwl(a,b/2,m);
    u = (u * u)%m;
    if (b % 2 == 1)
        u = (u*a)%m;
    return u;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll md = 1000000007;
    ll k,n;
    cin >> k >> n;
    for (ll i = n;i >= (n - k + 1);i--)
        factors(i);
    for (ll i = 1;i <= k;i++)
        factors2(i);
//    ll a = 1;
//    for (auto it : result){
//        a = (a*pwl(it.first,it.second,md))%md;
//    }
//
////    cout << a << endl;
//
////    ll ans = a;
    ll ans = 1;
    for (auto it : result){
        if (it.second > 0)
            ans = (ans *((ll)(pow(it.first,it.second) - pow(it.first,it.second - 1))%md))%md;
    }
    cout << ans%md << endl;


    return 0;
}