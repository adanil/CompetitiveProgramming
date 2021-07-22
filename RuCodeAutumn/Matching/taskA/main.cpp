#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int>>g;
vector<char>used;
vector<int>match;

bool dfs(int v){
    if (used[v])
        return false;
    used[v] = 1;

    for (auto to: g[v]){
        if (match[to] == -1 || dfs(match[to])) {
            match[to] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int n,m;
    cin >> n >> m;
    g.resize(n);

    for (int i = 0;i < n;i++){
        int el;
        cin >> el;
        while (el != 0) {
            el--;
            g[i].push_back(el);
            cin >> el;
        }
    }

    used.resize(n,0);
    match.resize(m,-1);
    for (int i = 0;i < n;i++){
        fill(used.begin(),used.end(),0);
        dfs(i);
    }
    vector<pair<int,int>>ansV;
    int ans = 0;
    for (int i = 0;i < m;i++){
        if (match[i] != -1){
            ans++;
            ansV.emplace_back(match[i] + 1,i + 1);
        }
    }

    cout << ans << endl;
    for (auto edge : ansV){
        cout << edge.first << ' ' << edge.second << endl;
    }
    return 0;
}