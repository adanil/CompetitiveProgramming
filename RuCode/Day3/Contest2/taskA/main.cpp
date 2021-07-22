#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

int main() {

    ll k;
    cin >> k;
    ll n = 0;
    vector<pair<int,int>>q(k);
    for (int i = 0;i < k;i++){
        ll x,y;
        cin >> x >> y;
        if (x > 0)
            n = max(n,y);
        q[i] = pair<int,int>(x,y);
    }
    vector<ll> a(n);
    for (auto &el : a){
        el = (n*n)%12345 + (n*n*n)%23456;
    }

    ll logn = 0;
    ll cp = n;
    while (cp > 0){
        logn++;
        cp >>= 1;
    }

    vector<vector<ll>> sptMin(n,vector<ll>(logn,0));
    sptMin[0] = a;

    return 0;
}