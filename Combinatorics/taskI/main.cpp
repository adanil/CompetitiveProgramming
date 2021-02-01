#include <iostream>
#include <vector>
#include <map>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    map<ll,int> mp;
    map<ll,int>dv;
    int n;
    cin >> n;
    vector<ll>a(n),b(n);
    for (auto &el : a) {
        cin >> el;
        mp[el]++;
    }
    for (auto &el : b) {
        cin >> el;
        mp[el]++;
    }
    ll m;
    cin >> m;


    int eq = 0;
    for (int i = 0;i < n;i++){
        if (a[i] == b[i])
            dv[a[i]]++;
    }

    ll k = 0;
    for (auto it = dv.begin();it != dv.end();it++){
        k += it->second;
    }

    ll ans = 1;
    for (auto it = mp.begin();it != mp.end();it++){
        for (int i = 1;i < it->second + 1;i++){
            int t = i;
            while (k > 0 && t % 2 == 0){
                t /= 2;
                k--;
            }
            ans *= t;
            ans %= m;
        }
    }
    cout << ans << endl;

    return 0;
}
