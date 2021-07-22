#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<pair<vector<int>,int>>g;
vector<char> used;
vector<bool>printed;

void dfs(int v){
    used[v] = 1;
    for (auto to: g[v].first){
        if (!used[to])
            dfs(to);
        g[v].second = min(g[v].second,g[to].second);
    }
    g[v].second = min(g[v].second,v);
}

void dfsAns(int v){
    used[v] = 1;
    set<int>q;
    sort(g[v].first.begin(),g[v].first.end(),[](auto a,auto b){
        return g[a].second < g[b].second;
    });
    for (auto to : g[v].first){
        if (!used[to]) {
            dfsAns(to);
        }
        q.insert(to + 1);
    }


    for (auto it : q) {
        if (!printed[it - 1]) {
            cout << it << ' ';
            printed[it-1] = true;
        }
    }
    cout.flush();

}

const int INF = 1000000000;

vector<int> depth;
vector<int>prv;

int main() {
    int n,m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    depth.resize(n,1);
    prv.resize(n,-1);
    printed.resize(n);
    for (int i = 0;i < n;i++)
        g[i].second = INF;
    for (int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[b].first.push_back(a);
        if (depth[a] != 1 && depth[b] + 1 <= depth[a]){
            g[b].first.erase(find(g[b].first.begin(),g[b].first.end(),a));
        }
        if (depth[b] + 1 > depth[a]){
        depth[a] = depth[b] + 1;
        prv[a] = b;
        }
    }
    for (int i = 0;i < n;i++)
        dfs(i);
    fill(used.begin(),used.end(),false);
    for (int i = 0;i < n;i++){
        if (!used[i]) {
            dfsAns(i);
            if (!printed[i]) {
                cout << i + 1 << ' ';
                printed[i] = true;
            }
        }
        cout.flush();
    }

    return 0;
}