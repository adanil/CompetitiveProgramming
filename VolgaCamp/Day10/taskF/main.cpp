#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;
using ll = long long;


vector<int>used;
vector<vector<int>>g;
queue<int>q;

vector<ll>dist;

const ll INF = 100000000000000000;

void bfs(){
    while (!q.empty()){
        int v = q.front();
        q.pop();

        for (auto to : g[v]){
            if (!used[to]){
                q.push(to);
                used[to] = 1;
            }
            dist[to] = min(dist[to],dist[v] + 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
//        g.resize(n);
//        used.resize(n);
//        dist.resize(n,INF);
        for (int i = 0;i < m;i++){
            int a,b;
            cin >> a >> b;
//            a--;b--;
//            g[a].push_back(b);
//            g[b].push_back(a);
        }
//        ll ans = 0;
//        for (int i = 0;i < n;i++){
//            q.push(i);
//            used[i] = 1;
//            dist[i] = 0;
//            bfs();
//            ans = max(ans,*max_element(dist.begin(),dist.end()));
//            fill(used.begin(),used.end(),0);
//            fill(dist.begin(),dist.end(),INF);
//        }
//        g.clear();

        cout << n - 1 << endl;
    }
    return 0;
}