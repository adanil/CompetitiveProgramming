#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int module = 998244353;

ll pw(ll a, ll n, int m) {
    ll r = 1 % m;
    while (n > 0) {
        if (n & 1) {
            r = ll(1LL * r * a % m);
        }
        a = ll(1LL * a * a % m);
        n >>= 1;
    }
    return r;
}

vector<int>allCoord;

ll getCoord(ll v){
    return lower_bound(allCoord.begin(),allCoord.end(),v) - allCoord.begin();
}

ll C(ll n,ll k,vector<int> &fac)
{
    if (n - k < 0)
        return 0;
    return (((fac[n] * 1ll * pw(fac[k] * 1ll,module - 2,module)) % module )* pw(fac[n-k] * 1ll,module - 2,module)) % module;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,k;
    cin >> n >> k;

    vector<pair<int,int>>line(n);
    allCoord.resize(n * 2);

    for (int i = 0;i < n;i++){
        cin >> line[i].first >> line[i].second;
        allCoord[i * 2] = line[i].first;
        allCoord[i * 2 + 1] = line[i].second;
    }

    sort(allCoord.begin(),allCoord.end());
    allCoord.erase(unique(allCoord.begin(),allCoord.end()),allCoord.end());

    vector<vector<int>>field(allCoord.size() + 1);

    // cout << field.size() << endl;
    for (int i = 0;i < n;i++){
        ll start = getCoord(line[i].first);
        ll end = getCoord(line[i].second);
        // cout << start << ' ' << end << endl;
        for (int j = start;j <= end;j++)
            field[j].push_back(i);
    }


    const ll maxn = 300000;
    vector<int>fac(maxn,1);
    for (int i = 1;i < maxn;i++){
        fac[i] = (fac[i - 1] * 1ll * i) % module;
    }



    set<int>together;
    ll ans = 0;

    for (int i = 0;i < field.size();i++){
        if (field[i].size() >= k){
            int olds = 0;
            for (auto el: field[i]){
                if (together.count(el) != 0)
                    olds++;
                together.insert(el);
            }
            ans += C(field[i].size(),k,fac) % module;
            ans %= module;
            ans -= C(olds,k,fac) % module;
            ans %= module;
            // cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}