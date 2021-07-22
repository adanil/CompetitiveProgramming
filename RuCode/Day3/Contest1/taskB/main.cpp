#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n;
    ll modulo = 1000000007;
    cin >> n;
    vector<ll>a(n);
    vector<ll>used(n+1,0);
    for (ll i = 0;i < n;i++){
        cin >> a[i];
    }
    vector<ll>p(n,1);
    for (ll i = 1;i < n;i++){
        p[i] = (p[i-1]*i)%modulo;
    }

    ll ans = 0;

    for (ll i = 0;i < n;i++){
        ll cnt = 0;
        for (ll j = 1;j < a[i];j++){
            if (!used[j]){
                ++cnt;
            }
        }
        ans += (((cnt) % modulo) * (p[n-i-1] % modulo))%modulo;
        used[a[i]] = 1;
    }
    cout << (ans + 1)%modulo << endl;

    return 0;
}