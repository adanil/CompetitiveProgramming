#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ld = long long;

const ld INF = 6000 * 1000000000000000 + 10;

struct edge{
    int a;
    int b;
    ld cost;
};


vector<char>used;
void dfs(int v,vector<vector<int>>gr){
    used[v] = 1;
    for (auto to : gr[v]){
        if (!used[to])
            dfs(to,gr);
    }
}


int main() {
    int n,m,s;
    cin >> n >> m >> s;
    s--;
    vector<edge>e(m);
    vector<vector<int>> gr(n);
    used.resize(n,0);
    for (int i = 0;i < m;i++){
        edge eg;
        int a,b;
        ld c;
        cin >> a >> b >> c;
        a--;
        b--;
        eg.a = a;
        eg.b = b;
        eg.cost = c;
        e[i] = eg;
        gr[a].push_back(b);
    }

    vector<ld> d (n, INF);
    d[s] = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                d[e[j].b] = min (d[e[j].b], d[e[j].a] + e[j].cost);



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
        ;//no neg cycle
        for (int i = 0;i < n;i++){
            if (d[i] == INF)
                cout << "*" << endl;
            else
                cout << d[i] << endl;
        }
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
        for (int i = 0;i < n;i++){
            if (used[i]) {
                if (d[i] == INF)
                    cout << "*" << endl;
                else
                    cout << "-" << endl;
            }
            else if (d[i] == INF)
                cout << "*" << endl;
            else
                cout << d[i] << endl;
        }


//        cout << "Negative cycle: ";
//        for (size_t i=0; i<path.size(); ++i)
//            cout << path[i] << ' ';
    }

    return 0;
}