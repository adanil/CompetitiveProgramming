#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll INF = 100000000000;




struct segTree{
    vector<pair<ll,ll>> tree;
    size_t n;

    void init(vector<pair<ll,ll>> &a){
        n = a.size();
        ll sz = 1;
        while (sz < n) sz *= 2;
        a.resize(sz,{INF,-1});
        tree.assign(2*sz - 1,{INF,-1});
        n = sz;
        for (ll i = 0;i < n;i++){
            tree[i + n - 1] = a[i];
        }
        for (ll i = n - 2;i >= 0;i--){
            tree[i] = min(tree[i * 2 + 1],tree[i * 2 + 2]);
        }
    }

//    void set(ll ind, ll el){
//        ll curr = ind + n - 1;
//        tree[curr] = el;
//
//        while(curr != 0) {
//            if (curr % 2 != 0)
//                curr = curr/2;
//            else
//                curr = curr/2 - 1;
//            tree[curr] = min(tree[curr * 2 + 1],tree[curr * 2 + 2]);
//        }
//    }

    pair<ll,ll> getMin(ll l,ll r,ll lx,ll rx,ll x){
        if (l >= rx || r <= lx)
            return {INF,-1};
        else if (lx >= l && rx <= r)
            return tree[x];

        ll m = (lx + rx)/2;
        pair<ll,ll> s1 = getMin(l,r,lx,m,2 * x + 1);
        pair<ll,ll> s2 = getMin(l,r,m,rx,2 * x + 2);
        return min(s1,s2);
    }

    pair<ll,ll> getMin(ll l,ll r){
        return getMin(l,r,0,n,0);
    }
};



struct segTreeMx{
    vector<pair<ll,ll>> tree;
    size_t n;

    void init(vector<pair<ll,ll>> &a){
        n = a.size();
        ll sz = 1;
        while (sz < n) sz *= 2;
        a.resize(sz,{-1,-1});
        tree.assign(2*sz - 1,{-1,-1});
        n = sz;
        for (ll i = 0;i < n;i++){
            tree[i + n - 1] = a[i];
        }
        for (ll i = n - 2;i >= 0;i--){
            tree[i] = max(tree[i * 2 + 1],tree[i * 2 + 2]);
        }
    }

//    void set(ll ind, ll el){
//        ll curr = ind + n - 1;
//        tree[curr] = el;
//
//        while(curr != 0) {
//            if (curr % 2 != 0)
//                curr = curr/2;
//            else
//                curr = curr/2 - 1;
//            tree[curr] = min(tree[curr * 2 + 1],tree[curr * 2 + 2]);
//        }
//    }

    pair<ll,ll> getMax(ll l,ll r,ll lx,ll rx,ll x){
        if (l >= rx || r <= lx)
            return {-1,-1};
        else if (lx >= l && rx <= r)
            return tree[x];

        ll m = (lx + rx)/2;
        pair<ll,ll> s1 = getMax(l,r,lx,m,2 * x + 1);
        pair<ll,ll> s2 = getMax(l,r,m,rx,2 * x + 2);
        return max(s1,s2);
    }

    pair<ll,ll> getMax(ll l,ll r){
        return getMax(l,r,0,n,0);
    }
};





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> a(n);
    for (int i = 0;i < n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    segTree sgt;
    sgt.init(a);

    segTreeMx sgtMx;
    sgtMx.init(a);


    for (int i = 0;i < m;i++){
        ll l,r,x;
        cin >> l >> r >> x;
        l--;
        auto mx = sgtMx.getMax(l,r);
        auto mn = sgt.getMin(l,r);
        if (mx.first != x){
            cout << mx.second + 1 << endl;
        }
        else if (mn.first != x){
            cout << mn.second + 1 << endl;
        } else
            cout << -1 << endl;
    }

    return 0;
}