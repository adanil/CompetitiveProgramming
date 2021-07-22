#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<char>used;
vector<vector<ll>>g;

void dfs(int v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to])
            dfs(to);
    }
}

int main() {
    ll n,m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n,0);
    ll ans = 0;
    for (int i = 0;i < m;i++){
        ll from,to;
        cin >> from >> to;
        from--;
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    for (int i = 0;i < n;i++){
        if (!used[i]) {
            dfs(i);
            ans++;
        }

    }
    cout << ans << endl;

    return 0;
}