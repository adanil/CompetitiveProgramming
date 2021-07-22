#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

//sumTree

struct segTree{
    vector<ll> tree;
    size_t n;

    void init(vector<ll> &a){
        n = a.size();
        ll sz = 1;
        while (sz < n) sz *= 2;
        a.resize(sz,0);
        tree.assign(2*sz - 1,0);
        n = sz;
        for (ll i = 0;i < n;i++){
            tree[i + n - 1] = a[i];
        }
        for (ll i = n - 2;i >= 0;i--){
            tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
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
            tree[curr] = tree[curr * 2 + 1] + tree[curr * 2 + 2];
        }
    }

    ll getSum(ll l,ll r,ll lx,ll rx,ll x){
        if (l >= rx || r <= lx)
            return 0;
        else if (lx >= l && rx <= r)
            return tree[x];

        ll m = (lx + rx)/2;
        ll s1 = getSum(l,r,lx,m,2 * x + 1);
        ll s2 = getSum(l,r,m,rx,2 * x + 2);
        return s1 + s2;
    }

    ll getSum(ll l,ll r){
        return getSum(l,r,0,n,0);
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
            cout << st.getSum(l, r) << endl;
        }
    }

    return 0;
}