#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <ctime>

using namespace std;

vector<char> used;

vector<int> enter,out;

static int tm = 0;


void dfs(int v,vector<vector<int>> &g){
    used[v] = true;
    enter[v] = tm++;
    for (auto it = g[v].begin();it != g[v].end();it++){
        if (!used[*it])
            dfs(*it,g);
    }
    out[v] = tm++;
}

int main() {
    ifstream fin("ancestor.in");
    ofstream fout("ancestor.out");
    int root;
    int n;
    fin >> n;
    vector<vector<int>> g(n);
    enter = vector<int>(n);
    out = vector<int>(n);
    for (int i = 0;i < n;i++){
        int a;
        fin >> a;
        if (a == 0){
            root = i;
            continue;
        }
        a--;
        g[a].push_back(i);
    }


    int m;
    used = vector<char>(n,false);
    dfs(root,g);
    fin >> m;
    for (int i = 0;i < m;i++){
        int a,b;
        fin >> a >> b;
        a--;
        b--;
        if ((enter[a] < enter[b]) && (out[b] < out[a]))
            fout << 1 << endl;
        else
            fout << 0 << endl;
    }


    return 0;
}