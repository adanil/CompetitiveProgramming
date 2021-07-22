#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll>ans;
    unordered_set<ll>mp;
    for (ll i = 0;i < n;i++){
        ll q;
        cin >> q;
        if (mp.count(q) == 0) {
            mp.insert(q);
            ans.push_back(q);
        }


    }
    cout << ans.size() << endl;
    for (ll a : ans)
        cout << a << ' ';


    return 0;
}