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

set<int>soc;

void dfs(int v ,int p ,vector<vector<edge>> &g){
    used[v] = true;
    tin[v] = t++;
    d[v] = tin[v];
    int children = 0;
    for (auto e : g[v]){
        if (p == e.to)
            continue;
        if (!used[e.to]){
            dfs(e.to,v,g);
            d[v] = min(d[v],d[e.to]);
            children++;
            if (tin[v] <= d[e.to] && p != -1) {
                soc.insert(v+1);
            }
        }
        else{
            d[v] = min(d[v],tin[e.to]);
        }
    }
    if (children > 1 && p == -1)
        soc.insert(v+1);

}


int main() {
    ifstream fin("points.in");
    ofstream fout("points.out");

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

    fout << soc.size() << endl;
    for (auto b : soc){
        fout << b << endl;
    }
    return 0;
}