#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;


vector<vector<ll>>g;
vector<char>used;
vector<char>lux;

void dfs(ll v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to] && !lux[to])
            dfs(to);
    }
}

int main() {
    ll n,k,m;
    cin >> n >> k >> m;
    g.resize(n);
    used.resize(n,0);
    lux.resize(n,0);
    vector<ll>kn(k);
    for (int i = 0;i < k;i++){
        ll el;
        cin >> el;
        el--;
        lux[el] = 1;
        kn[i] = el;
    }
    for (int i = 0;i < m;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    for (int i = 0;i < k;i++){
        if (!used[kn[i]])
            dfs(kn[i]);
    }
    for (int i = 0;i < n;i++){
        if (used[i] == 0){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}