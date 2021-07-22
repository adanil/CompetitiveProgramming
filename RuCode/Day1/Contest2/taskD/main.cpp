#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;

struct edge{
    short a;
    short b;
    short cost;
};


vector<char>used;
void dfs(short v,vector<vector<short>>&gr){
    used[v] = 1;
    for (auto to : gr[v]){
        if (!used[to])
            dfs(to,gr);
    }
}


int main() {
    short n,m;
    cin >> n >> m;
    vector<edge>e(m);
    vector<vector<short>>gr(n);
    used.resize(n,0);
    for (int i = 0;i < m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        edge eg;
        eg.a = a;
        eg.b = b;
        eg.cost = -w;
        e[i] = eg;

        gr[a].push_back(b);
    }

    int start = 0;
    vector<int> d (n, INF);
    d[start] = 0;

    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);

    int ans = 0;
    if (d[n-1] != INF)
        ans = d[n-1];
    if (d[n-1] == INF){
        cout << ":(" << endl;
        return 0;
    }

    vector<int> p (n, -1);
    int x;
    for (int i=0; i<n; ++i) {
        x = -1;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = max (-INF, d[e[j].a] + e[j].cost);
                    p[e[j].b] = e[j].a;
                    x = e[j].b;
                }
    }

    if (x == -1) {
        cout << -ans << endl;
        return 0;
    }
    else {
        int y = x;
        for (int i=0; i<n; ++i)
            y = p[y];

        vector<int> path;
        for (int cur=y; ; cur=p[cur]) {
            path.push_back (cur);
            if (cur == y && path.size() > 1)  break;
        }
        reverse (path.begin(), path.end());

        for (auto nc : path){
            dfs(nc,gr);
        }
        if (used[n-1])
            cout << ":)" << endl;
        else
            cout << -ans << endl;
        return 0;
    }







    return 0;
}