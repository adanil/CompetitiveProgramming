#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int n;
vector<vector<pair<int,int>>>g;
vector<char>used;
const ll INF = 1000000000000000000;

void dijkstra(vector<ll> &dist,int s){
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
        v = j;
        if (dist[v] == INF)
            break;
        used[v] = true;

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second;
            if (dist[v] + len < dist[to]) {
                dist[to] = dist[v] + len;
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >> test;
    while(test--){
        int m,t;
        cin >> n >> m >> t;
        g.resize(n);
        used.resize(n,0);
        int s,gd,hd;
        cin >> s >> gd >> hd;
        s--;
        gd--;
        hd--;
        for (int i = 0;i < m;i++){
            ll a,b,w;
            cin >> a >> b >> w;
            a--;b--;
            g[a].emplace_back(b,w);
            g[b].emplace_back(a,w);
        }
        vector<int>dests(t);
        for (auto &el : dests) {
            cin >> el;
            el--;
        }
        vector<ll> distStart(n,INF);
        distStart[s] = 0;
        vector<ll> distG(n,INF);
        distG[gd] = 0;
        vector<ll> distH(n,INF);
        distH[hd] = 0;
        dijkstra(distStart,s);
        fill(used.begin(),used.end(),0);
        dijkstra(distG,gd);
        fill(used.begin(),used.end(),0);
        dijkstra(distH,hd);

        ll ghdist = distG[hd];

        set<int>ans;
        for (int i = 0;i < t;i++){
            if (distStart[dests[i]] == distStart[gd] + distG[dests[i]]&&distStart[gd] == distStart[hd] + ghdist){
                ans.insert(dests[i]);
            }
            if (distStart[dests[i]] == distStart[hd] + distH[dests[i]]&&distStart[hd] == distStart[gd] + ghdist){
                ans.insert(dests[i]);
            }
        }
        for (auto it = ans.begin();it != ans.end();it++){
            cout << *it + 1 << ' ';
        }
        cout << endl;
        g.clear();
        used.clear();

    }
    return 0;
}