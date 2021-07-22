#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;


#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

int main() {
    int k, n, m;
    pair<int, int> start, end;
    vector<vector<int>> table(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
            if (table[i][j] == 2)
                start = make_pair(i, j);
            if (table[i][j] == 3)
                end = make_pair(i, j);
        }
    }

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j > 0 && table[i][j - 1] == 0)
                g[i * m + j][i * m + j - 1] = 1;
            if (j < m - 1 && table[i][j + 1] == 0)
                g[i * m + j][i * m + j + 1] = 1;
            if (i > 0 && table[i - 1][j] == 0)
                g[i * m + j][i * m + j - m] = 1;
            if (i < n - 1 && table[i + 1][j] == 0)
                g[i * m + j][i * m + j + m] = 1;

        }
    }
    int s = start.first * m + start.second;


    queue<int> q;
    q.push (s);
    vector<bool> used (n);
    vector<int> d (n), p (n);
    vector<int> right(n);
    int prev;
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[i] && to == 1) {
                if (prev)
                used[i] = true;
                q.push (i);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
        prev = v;
    }

    return 0;
}