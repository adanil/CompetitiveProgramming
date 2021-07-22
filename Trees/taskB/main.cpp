#include <iostream>
#include <vector>
#include <map>

using ll = long long;
using namespace std;

vector<vector<ll>>g;
vector<ll>sizes;
vector<ll>numb;
vector<ll>values;
map<ll,ll>indices;
vector<ll>indValues;


struct fenwick {
    vector<ll> tree;

    void init(size_t sz) {
        tree.resize(sz + 1, 0);
    }

    ll sum(int k) {
        ll s = 0;
        while (k >= 1) {
            s += tree[k];
            k -= k & -k;
        }
        return s;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int pos, ll val) {
        while (pos <= tree.size() -1) {
            tree[pos] += val;
            pos += pos & -pos;
        }
    }
};


void dfs(int v,int prev){
    numb.push_back(v);
    indValues.push_back(values[v]);
    sizes[v] = 1;
    indices[v] = numb.size() - 1;
    for (auto to : g[v]){
        if (to != prev) {
            dfs(to, v);
            sizes[v] += sizes[to];
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    g.resize(n);
    values.resize(n);
    sizes.resize(n,0);
    for (int i = 0;i < n - 1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    fenwick fw;
    fw.init(n);
    for (int i = 0;i < n;i++){
        cin >> values[i];
    }
    dfs(0,-1);

    for (int i = 0;i < n;i++){
        fw.add(i + 1,indValues[i]);
    }

    ll q;
    cin >> q;
    while (q--){
        ll u,x;
        cin >> u >> x;
        u--;
        ll ind = indices[u];
        ll sum = fw.sum(ind + 1,ind + sizes[u]);
        ll diff = x - indValues[ind];
        indValues[ind] = x;
        fw.add(ind + 1,diff);
        cout << sum << endl;
    }
    return 0;
}