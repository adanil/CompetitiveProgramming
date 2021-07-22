#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    map<ll,vector<ll>> ekz;
    for (int i = 0;i < n;i++){
        ll a,b;
        cin >> a >> b;
        ekz[a].push_back(b);
    }
    ll ans = -1;
    for (auto it = ekz.begin();it != ekz.end();it++){
        sort(it->second.begin(),it->second.end());
    }
    for (auto it = ekz.begin();it != ekz.end();it++){
        for (int i = 0;i < it->second.size();i++) {
            if (it->second[i] < ans)
                ans = it->first;
            else
                ans = it->second[i];
        }
    }
    cout << ans << endl;
    return 0;
}