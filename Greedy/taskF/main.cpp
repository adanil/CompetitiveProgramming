#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;
using ll = long long;
vector<vector<ll>> g;
vector<tuple<ll, ll,ll>> depths;
vector<ll> tin;
vector<ll> tout;
vector<char> used;
ll t = 0;
ll depth = 0;


void dfs(int v) {
    used[v] = 1;
    get<0>(depths[v]) = ++depth;
    tin[v] = ++t;
    for (auto to : g[v])
        if (!used[to])
            dfs(to);

    depth--;
    tout[v] = t;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    g.resize(n);
    depths.resize(n);
    tin.resize(n);
    tout.resize(n);
    used.resize(n);

    for (int i = 0; i < n - 1; i++) {
        ll f, t;
        cin >> f >> t;
        f--;
        t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    dfs(0);
    for (int i = 0; i < n; i++)
        get<1>(depths[i]) = i;


    for (int i = 0;i < n;i++){
        get<2>(depths[i]) = tout[i] - tin[i];
    }

    sort(depths.begin(),depths.end(),[](tuple<ll,ll,ll> a,tuple<ll,ll,ll>b){
        return get<0>(a) - get<2>(a) > get<0>(b) - get<2>(b);
    });

    ll ans = 0;
    for (int i = 0;i < k;i++){
        ans += get<0>(depths[i]) - get<2>(depths[i]) - 1;
    }
    cout << ans << endl;


    return 0;
}


//Выбор оптимальной вершины по глубине, к ответу + глубина
//Проверка, если это предок уже выбранный вершин, то -1 * количество потомков
//O(k * log(k))