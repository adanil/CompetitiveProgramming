#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> depth;
vector<int> tout;

int t = 0;

void bfs(int s,vector<vector<int>> &g){
    queue<int> q;
    q.push (s);
    int n = g.size();
    depth[s] = t++;
    vector<bool> used (n);
    vector<int> d (n), p (n);
    used[s] = true;
    p[s] = -1;
    int cntLayer = 1;
    int locLayer = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                depth[to] = t;
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
        locLayer += g[v].size();
        if (cntLayer == locLayer){
            locLayer = 0;
            t++;
            cntLayer = q.size();
        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n);
    depth.resize(n);
    tout.resize(n);
    for (int i = 0;i < n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
    }
    bfs(0,g);
    cout << "Hi" << endl;
    return 0;
}