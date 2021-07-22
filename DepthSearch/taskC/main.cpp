#include <iostream>
#include <vector>
#include <set>
#include <fstream>

using namespace std;

struct edge{
    int from;
    int to;
    int numb;
    bool isBridge = false;
};

vector<char> used;
vector<int> tin;
vector<int>d;
int t = 1;

set<int>bridges;

void dfs(int v ,int p ,vector<vector<edge>> &g){
    used[v] = true;
    tin[v] = t++;
    d[v] = tin[v];
    for (auto e : g[v]){
        if (p == e.to)
            continue;
        if (!used[e.to]){
            dfs(e.to,v,g);
            d[v] = min(d[v],d[e.to]);
            if (tin[v] < d[e.to]) {
                e.isBridge = true;
                bridges.insert(e.numb);
            }
        }
        else{
            d[v] = min(d[v],tin[e.to]);
        }
    }

}


int main() {
    ifstream fin("bridges.in");
    ofstream fout("bridges.out");

    int n,m;
    fin >> n >> m;
    vector<vector<edge>>g(n);
    used = vector<char>(n,false);
    tin = vector<int>(n);
    d = vector<int>(n);
    for (int i = 0;i < m;i++){
        edge e;
        fin >> e.from >> e.to;
        e.from--;
        e.to--;
        e.numb = i+1;
        edge erev;
        erev.from = e.to;
        erev.to = e.from;
        erev.numb = e.numb;
        g[e.from].push_back(e);
        g[e.to].push_back(erev);
    }
    for (int i = 0;i < n;i++) {
        dfs(i, -1, g);
    }

    fout << bridges.size() << endl;
    for (auto b : bridges){
        fout << b << endl;
    }
    return 0;
}