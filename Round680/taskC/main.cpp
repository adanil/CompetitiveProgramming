#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;
using ll = long long;

vector<ll> factorize(ll x) {
    vector<ll> factors;

    for (ll i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    if (x != 1) {
        factors.push_back(x);
    }

    return factors;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll>primes;

//
//    ll n = 1e7 + 5*1e6;
//    static vector<char> prime (n, true);
//    prime[0] = prime[1] = false;
//    for (ll i=2; i*i<=n; ++i) {
//        if (prime[i]) {
//            if (i * 1ll * i <= n) {
//                for (ll j = i * i; j <= n ; j += i) {
//                    if (j < n)
//                        prime[j] = false;
//                    else
//                        break;
//                }
//            }
//        }
//    }
//
//    primes.push_back(1);
//    for (int i = 2;i < n;i++){
//        if (prime[i]) {
//            primes.push_back(i);
//        }
//    }




    int t;
    cin >> t;
    while(t--){
       ll p,q;
       cin >> p >> q;
       vector<ll> fq = factorize(q);
       ll ans = 0;
       for (int i = 0;i < fq.size();i++) {
           ll tmp = p;
           while (tmp % q == 0) {
               tmp /= fq[i];
           }
           ans = max(ans, tmp);
       }



       cout << ans << endl;
    }

    return 0;
}