#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <unordered_set>

using namespace std;
using ll = long long;

struct mst{
    ll val;
    ll i;
    ll j;

    mst(ll val, ll i, ll j) : val(val), i(i), j(j) {}
};

bool operator<(mst a,mst b){
    return a.val < b.val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll>a(n);
    ll sa = 0,sb = 0;
    for (auto &el : a) {
        cin >> el;
        sa += el;
    }
    ll m;
    cin >> m;
    vector<ll>b(m);
    for (auto &el : b) {
        cin >> el;
        sb += el;
    }
    ll diff = sa - sb;
    ll k = 0;
    pair<ll,ll>q,w;
    for (ll i = 0;i < n;i++){
        for (ll j = 0;j < m;j++){
            if (abs(diff) > abs(sa - a[i] + b[j] - (sb - b[j] + a[i]))){
                k = 1;
                diff = sa - a[i] + b[j] - (sb - b[j] + a[i]);
                q = {i + 1,j + 1};
            }
        }
    }

    set<mst> ap,bp;
//    for (ll i = 0;i < n;i++){
//        for (ll j = i + 1;j < n;j++){
//            ap.insert(mst(a[i] + a[j],i,j));
//        }
//    }

    for (ll i = 0;i < m;i++){
        for (ll j = i + 1;j < m;j++){
            bp.insert(mst(b[i] + b[j],i,j));
        }
    }


    // (sa - it + x) - (sb + it - x) = 0
    // sa - it + x - sb - it + x = 0
    // x = (sb - sa + 2 * it)/2

    if (bp.size() > 0) {
        for (ll i = 0;i < n;i++) {
            for (ll j = i + 1;j < n;j++){
                auto lb = bp.lower_bound({(ll) (sb - sa + 2 * (a[i] + a[j])) / 2, -1, -1});
                if (lb == bp.end())
                    lb--;
                if (abs(diff) > abs((ll) (sa - (a[i] + a[j]) + lb->val - sb - (a[i] + a[j]) + lb->val))) {
                    diff = sa - (a[i] + a[j]) + lb->val - sb -(a[i] + a[j]) + lb->val;
                    k = 2;
                    q = {i + 1, lb->i + 1};
                    w = {j + 1, lb->j + 1};
                }
            }
        }
    }

    cout << abs(diff) << endl;
    cout << k << endl;
    if (k == 1){
        cout << q.first << ' ' << q.second << endl;
    }
    else if (k == 2){
        cout << q.first << ' ' << q.second << endl;
        cout << w.first << ' ' << w.second << endl;
    }

    return 0;
}