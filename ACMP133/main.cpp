#include <iostream>
#include <vector>
#include <utility>
const int INF = 1000000000;

using namespace std;

int main() {

    int n,m;
    cin >> n;
    vector<int> cost(n);
    for (int i = 0; i < n;i++){
        cin >> cost[i];
    }
    cin >> m;
    vector < vector < pair<int,int> > > g (n);
    for (int i = 0; i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(make_pair(b,cost[a]));
        g[b].push_back(make_pair(a,cost[b]));
    }
    int s = 0; // стартовая вершина

    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    vector<char> u (n);
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    if (!u[n-1])
        cout << -1 << endl;
    else
        cout << d[n-1] << endl;

    return 0;
}