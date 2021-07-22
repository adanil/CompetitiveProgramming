#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using ll = long long;


const ll INF = -100000;

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
            tree[i] = max(tree[i * 2 + 1],tree[i * 2 + 2]);
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
            tree[curr] = max(tree[curr * 2 + 1],tree[curr * 2 + 2]);
        }
    }

    ll getMax(ll l,ll r,ll lx,ll rx,ll x){
        if (l >= rx || r <= lx)
            return INF;
        else if (lx >= l && rx <= r)
            return tree[x];

        ll m = (lx + rx)/2;
        ll s1 = getMax(l,r,lx,m,2 * x + 1);
        ll s2 = getMax(l,r,m,rx,2 * x + 2);
        return max(s1,s2);
    }

    ll getMax(ll l,ll r){
        return getMax(l,r,0,n,0);
    }
};





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll>ones(n);
    ll ans = 0;
    for (ll i = 0;i < n;i++){
        ll el;
        ll cones = 0;
        cin >> el;
        while (el > 0){
            if (el & 1 == 1)
                cones++;
            el >>=1;
        }
        ones[i] =cones;
    }
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }

    segTree st;
    st.init(ones);


    ll currSum = ones[0];
    vector<ll>pref(n);
    pref[0] = ones[0];

    for (ll i = 1;i < n;i++){
        currSum += ones[i];
        pref[i] = currSum;
        if (currSum % 2 == 0) {
            ll mx = st.getMax(0,i);
            if (mx <= currSum - mx)
                ans++;
        }
        for (ll j = 0;j < i - 1;j++){
            if ((currSum - pref[j]) % 2 == 0) {
                ll mx = st.getMax(j + 1,i);
                if (mx <= currSum - pref[j] - mx)
                    ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}