#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    map<ll,int> mp;
    int mx = 0;
    ll ans = 0;
    for (int i = 0;i < n;i++){
        ll el;
        cin >> el;
        mp[el]++;
        if (mp[el] > ans)
            ans = mp[el];
    }
    cout << ans << endl;
    return 0;
}