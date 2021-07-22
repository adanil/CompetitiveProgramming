#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const ll INF = 100000000000;

//minTree

struct segTree{
    vector<ll> tree;
    size_t n;

    void init(vector<ll> &a){
        n = a.size();
        ll sz = 1;
        while (sz < n) sz *= 2;
        a.resize(sz,INF);
        tree.assign(2*sz - 1,INF);
        n = sz;
        for (ll i = 0;i < n;i++){
            tree[i + n - 1] = a[i];
        }
        for (ll i = n - 2;i >= 0;i--){
            tree[i] = min(tree[i * 2 + 1],tree[i * 2 + 2]);
        }
    }

    void set(ll ind, ll el){
        ll curr = ind + n - 1;
        tree[curr] = el;

        while(curr != 0) {
            if (curr % 2 != 0)
                curr = curr/2;
            else
                curr = curr/2 - 1;
            tree[curr] = min(tree[curr * 2 + 1],tree[curr * 2 + 2]);
        }
    }

    ll getMin(ll l,ll r,ll lx,ll rx,ll x){
        if (l >= rx || r <= lx)
            return INF;
        else if (lx >= l && rx <= r)
            return tree[x];

        ll m = (lx + rx)/2;
        ll s1 = getMin(l,r,lx,m,2 * x + 1);
        ll s2 = getMin(l,r,m,rx,2 * x + 2);
        return min(s1,s2);
    }

    ll getMin(ll l,ll r){
        return getMin(l,r,0,n,0);
    }
};


int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &el : a){
        cin >> el;
    }
    segTree st;
    st.init(a);
    for (ll i = 0;i < m;i++){
        short q;
        cin >> q;
        if (q == 1) {
            ll ind,u;
            cin >> ind >> u;
            st.set(ind, u);
        }
        else {
            ll l,r;
            cin >> l >> r;
            cout << st.getMin(l, r) << endl;
        }
    }

    return 0;
}