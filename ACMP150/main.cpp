#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,s;
    cin >> n >> s;
    vector<vector<int>>g(n,vector<int>(n));
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++)
            cin >> g[i][j];
    }
    s -= 1;
    queue<int> q;
    q.push (s);
    vector<bool> used (n);
    vector<int> d (n), p (n);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (!used[i] && to == 1) {
                used[i] = true;
                q.push (i);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    int ans = 0;
    for (int i = 0;i < n;i++) {
        if (used[i]) {
            ans++;
        }
    }
    cout << ans-1 << endl;
    return 0;
}