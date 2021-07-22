#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using ll = long long;

vector<char>used;
vector<vector<ll>>g;
map<int,vector<int>>toDel;
vector<pair<int,int>>data;

ll delCnt = 0;

void dfs(int v,int p){
    used[v] = 1;
    for (auto to : g[v]){
        if (used[to] && to != p && toDel[to][v] == -1){
            toDel[v][to] = 1;
            toDel[to][v] = 1;
            delCnt++;
        }
        if (!used[to])
            dfs(to,v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n,0);
    for (int i = 0;i < n;i++){
        toDel[i].resize(n,-1);
    }
    ll ans = 0;
    for (int i = 0;i < m;i++){
        ll from,to;
        cin >> from >> to;
        from--;
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
        data.push_back(make_pair(from,to));
    }

    for (int i = 0;i < n;i++){
        if (!used[i]) {
            dfs(i,-1);
            ans++;
        }

    }
    if (ans > 1){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
        cout << m - delCnt << endl;
        for (int i = 0;i < data.size();i++){
            if (toDel[data[i].first][data[i].second] == -1)
                cout << data[i].first + 1 << ' ' << data[i].second + 1 << endl;
        }

    }

    return 0;
}