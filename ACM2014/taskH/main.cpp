#include <iostream>
#include <vector>
#include <queue>


using namespace std;
using ll = long long;

vector<vector<int>>g;
vector<vector<int>>bfsMap;
vector<vector<int>>prevMap;
vector<char>used;
vector<int>p;
vector<int>d;

vector<pair<int,int>>diams;


int bfs(int v){
    queue<int> q;
    q.push (v);

    int ans = 0;
    used[v] = true;
    p[v] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
                ans = max(ans,d[to]);
                p[to] = v;
            }
        }
    }
    return ans;

}

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    g.resize(n);
    diams.resize(n);
    bfsMap.resize(n);
    for (int i = 0;i < m;i++){
        int from,to;
        cin >> from >> to;
        from--;to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    for (int i = 0;i < n;i++){
        used.resize(n,false);
        p.resize(n);
        d.resize(n);
        int mx = bfs(i);
        diams.emplace_back(mx,i);
        bfsMap[i] = d;
        prevMap[i] = p;
    }
    sort(diams.begin(),diams.end());



    return 0;
}