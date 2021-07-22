#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

vector<vector<pair<ll,ll>>>g;
vector<char>used;
map<ll,set<ll>>ans;
vector<ll>pr;

void dfs(int v,int p){
    pr[v] = p;
    used[v] = 1;
    auto to = g[v].begin();
    while (to != g[v].end()){
        ll toInd = to->first;
        if (to->second == 0 && ans[v].count(to->first) == 0){
            ans[to->first].insert(v);
            to = g[v].erase(to);
        }
        else
            to++;
        if (!used[toInd])
            dfs(toInd,v);
    }
}

void dfs2(int v,int p){
    used[v] = 1;
    for (auto to : g[v]){
        if (used[to.first]){

        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        g.resize(n);
        pr.resize(n);
        ll cnt = 0;
        for (int i = 0;i < m;i++){
            ll ty,fr,to;
            cin >> ty >> fr >> to;
            fr--;to--;
            if (ty == 1){
                g[fr].emplace_back(to,ty);
            }
            else{
                cnt++;
                g[fr].emplace_back(to,ty);
                g[to].emplace_back(fr,ty);
            }
        }
        used.resize(n,0);
        for (int i = 0;i < n;i++){
            if (!used[i])
                dfs(i);
        }

    }
    return 0;
}