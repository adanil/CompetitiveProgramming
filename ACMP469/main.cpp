#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int INF = 1000000000;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> t(n,vector<int>(m));
    for (int i = 0;i < n;i++) {
        for (int j = 0; j < m; j++)
            cin >> t[i][j];
    }

    vector<vector<pair<int,int>>> g(n*m);
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            if ( i - 1 >= 0) // up
                g[m*i + j].push_back(make_pair(m*(i-1) + j,t[i-1][j]));
            if (j - 1 >= 0) // left
                g[m*i + j].push_back(make_pair(m*i + j - 1,t[i][j-1]));
            if (i + 1 < n) // down
                g[m*i + j].push_back(make_pair(m*(i+1) + j,t[i+1][j]));
            if (j + 1 < m) // right
                g[m*i + j].push_back(make_pair(m*i + j+1,t[i][j+1]));
        }
    }

    int s = 0; // стартовая вершина
    n = n*m;
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


//    for (int i = 0;i < d.size();i++)
//        cout << d[i] << " ";
//    cout << endl;
//
//    for (int i = 0;i < n;i++){
//        for (int j = 0;j < g[i].size();j++)
//            cout << g[i][j].first << " ";
//        cout << endl;
//    }
//    cout << "ans: " << endl;
    cout << d.back() + t[0][0];

    return 0;
}