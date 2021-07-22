#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = -1;




struct segTreeSum{
    vector<ll> tree;
    size_t n;

    void init(vector<ll> a){
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


struct segTree{
    vector<ll> tree;
    size_t n;

    void init(vector<ll> a){
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
        return min(s1,s2);
    }

    ll getMax(ll l,ll r){
        return getMax(l,r,0,n,0);
    }
};







static int t = 0;
static int maxDepth = -1;
vector<vector<int>>g;
vector<char>used;
map<int,vector<int>> depth;
//vector<int>tin,tout;
vector<int>leaves;
vector<pair<int,int>>borderLeaves; // [l,r)
static int lvCnt = 0;

void dfs(int v,int d = 0){
    maxDepth = max(maxDepth,d);
//    tin[v] = t;
//    t++;
    used[v] = 1;
    if (!g[v].empty())
        depth[d].push_back(v);
    int left = lvCnt;
    if (g[v].empty()) {
        leaves.push_back(v);
        lvCnt++;
    }
    for (auto to : g[v]){
        if (!used[to])
            dfs(to,d + 1);
    }
    borderLeaves[v] = {left,lvCnt};
//    tout[v] = t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    g.resize(n);
    for (int i = 0;i < n - 1;i++){
        int el;
        cin >> el;
        el--;
        g[el].push_back(i + 1);
    }
    vector<ll>wgt(n);
    for (int i = 0;i < n;i++)
        cin >> wgt[i];
    used.resize(n,0);
//    tin.resize(n);
//    tout.resize(n);
    borderLeaves.resize(n);
    dfs(0);
    used.clear();

    vector<ll>leavesWgt(leaves.size());
    for (int i = 0;i < leaves.size();i++){
        leavesWgt[i] = wgt[leaves[i]];
    }

    segTree sgt;
    sgt.init(leavesWgt);

    segTreeSum sgtSum;
    sgtSum.init(leavesWgt);


    auto it = depth.end();
    it--;
    while(it != depth.begin()){
        for (const auto &v : it->second){
            int left = borderLeaves[v].first;
            int right = borderLeaves[v].second;
//            cout << left << ' ' << right << endl;
            if (left  == right)
                right++;
            ll value = wgt[v];
            ll mx = sgt.getMax(left,right);
            ll sum = sgtSum.getSum(left,right);
            value -= mx*(right - left) - sum;
            if (value > 0){
                ll nmx = mx;
                if (value % (right - left) == 0)
                    nmx += value/(right - left);
                else
                    nmx += value/(right - left) + 1;
                sgt.set(left,nmx);
            }
            sgtSum.set(left,mx + value);
        }
        it--;
    }
    for (const auto &v : it->second){
        int left = borderLeaves[v].first;
        int right = borderLeaves[v].second;
//        cout << left << ' ' << right << endl;
        if (left  == right)
            right++;
        ll value = wgt[v];
        ll mx = sgt.getMax(left,right);
        ll sum = sgtSum.getSum(left,right);
        value -= mx*(right - left) - sum;
        if (value > 0){
            ll nmx = mx;
            if (value % (right - left) == 0)
                nmx += value/(right - left);
            else
                nmx += value/(right - left) + 1;
            sgt.set(left,nmx);
        }
        sgtSum.set(left,mx + value);
    }

    cout << sgt.getMax(0,leavesWgt.size()) << endl;



    return 0;
}