#include <iostream>
#include <vector>
#include <cmath>


using namespace std;
using ll = long long;
int main() {
    ll max = 50000001;
    vector<int>prime(max,0);
    prime[1] = 1;
    for (ll i = 2;i*i < max;i++){
        if (prime[i])
            continue;
        for (ll j = 2*i;j < max;j += i)
            prime[j] = 1;
    }


    ll n;
    cin >> n;
    for (ll i = 0;i < n;i++){
        ll x;
        cin >> x;
        if (!prime[x])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return 0;
}