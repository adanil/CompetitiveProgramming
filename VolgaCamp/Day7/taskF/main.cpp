#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<char>used;

const ll INF = 30000;

struct edge{
    int from;
    int to;
    ll wgt;
};

vector<edge> g;
vector<ll>dist;

ll n,m;

void fordBellman(int v){
    dist[v] = 0;
    for (int i = 0;i < n-1;i++){
        for (int j = 0;j < m;j++){
            if (dist[g[j].from] < INF){
                dist[g[j].to] = min(dist[g[j].to],dist[g[j].from] + g[j].wgt);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    dist.resize(n,INF);
    for (int i = 0;i < m;i++){
        edge e;
        cin >> e.from >> e.to >> e.wgt;
        e.from--;
        e.to--;
        g.push_back(e);
    }
    fordBellman(0);
    for (int i = 0;i < n;i++)
        cout << dist[i] << ' ';
    cout << endl;
    return 0;
}