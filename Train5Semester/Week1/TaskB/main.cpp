#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct edge{
    ll from;
    ll to;
    ll wgt;
};

vector<vector<edge>>g;
vector<char>used;
vector<ll>d;
const ll INF = 999999999999;

void dfs(vector<vector<edge>>&g,int v){
    used[v] = true;
    for (auto to : g[v])
    {
        if (!used[to.to]){
            d[to.to] = min(d[v] + to.wgt,d[to.to]);
            dfs(g,to.to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    g.resize(n);
    d.resize(n,INF);
    d[0] = 0;
    used.resize(n);

    ll totalW = 0;
    for (int i = 0;i < n - 1;i++){
        ll from,to,wgt;
        cin >> from >> to >> wgt;
        from--;
        to--;
        g[from].push_back({from,to,wgt});
        g[to].push_back({to,from,wgt});
        totalW += 2*wgt;
    }
    dfs(g,0);

    cout << totalW - *max_element(d.begin(),d.end()) << endl;



    return 0;
}
