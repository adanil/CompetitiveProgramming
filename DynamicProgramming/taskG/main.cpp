#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
using ll = long long;

vector<vector<ll>>g;

vector<ll>dp;
vector<char>used;

ll start = 0;

void dfs(ll v,ll wgt){
    used[v] = 1;
    dp[v] = max(dp[v],wgt + start);
    for (auto to : g[v]){
        if (!used[to])
            dfs(to,wgt+1);
    }
}

int main() {
    ifstream fin("longpath.in");
    ofstream fout("longpath.out");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    ll n,m;
    fin >> n >> m;
    g.resize(n);
    dp = vector<ll>(n,0);
    used.resize(n);
    vector<pair<ll,ll>>in(n);
    for (int i = 0;i < n;i++)
        in[i].second = i;
    for (int i = 0;i < m;i++){
        ll from,to;
        fin >> from >> to;
        from--;
        to--;
        g[from].push_back(to);
        in[to].first++;
    }

    sort(in.begin(),in.end());

    for (auto el : in){
        ll i = el.second;
        start = dp[i];
        fill(used.begin(),used.end(),0);
        dfs(i,0);
    }
    fout << *max_element(dp.begin(),dp.end()) << endl;
    return 0;
}