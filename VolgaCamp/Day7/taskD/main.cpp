#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

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
    ifstream fin ("INPUT.TXT");
    ofstream fout("OUTPUT.TXT");
    int n;
    fin >> n;
    g.resize(n);
    used.resize(n);
    dist.resize(n,INF);
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++){
            int a;
            fin >> a;
            if (a == 1)
                g[i].push_back(j);
        }
    }

    int start,target;
    fin >> start >> target;
    start--;
    target--;
    q.push(start);
    used[start] = 1;
    dist[start] = 0;
    bfs();
    if (dist[target] != INF)
        fout << dist[target] << endl;
    else
        fout << -1 << endl;
    return 0;
}