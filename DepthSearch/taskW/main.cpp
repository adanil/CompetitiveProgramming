#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>g;
vector <char> used;
vector<vector<int>>cycles;
vector<int> prv;

void dfs(int v,int p){
    used[v] = 1;
    for (auto to : g[v]){
        if (to == p) continue;
        if (!used[to]) {
            prv[to] = v;
            dfs(to, v);
        }
        else if (used[to] == 1){
            vector<int> cycle;
            int start = to;
            int curr = v;
            while (prv[curr] != start){
                cycle.push_back(curr);
                curr = prv[curr];
            }
            cycle.push_back(curr);
            cycle.push_back(start);
            reverse(cycle.begin(),cycle.end());
            cycles.push_back(cycle);
        }
    }
    used[v] = 2;
}


int edgeCount = 0;
int vertCount = 0;
int flc = false;

void isTree(int v,int p){
    used[v] = 1;
    vertCount++;
    edgeCount += g[v].size();
    if (p != -1)
        edgeCount--;
    for (auto to : g[v]){
        if (to == p) continue;
        if (!used[to]){
            isTree(to,v);
        }
        else if (used[to] == 1)
            flc = true;
    }



}


int main() {

    int n,m;
    cin >> n >> m;
    used = vector<char> (n,0);
    g = vector<vector<int>>(n);
    prv = vector<int>(n);
    for (int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0,-1);
    for (int i = 0;i < n;i++){
        if (!used[i]){
            cout << "NO" << endl;
            return 0;
        }
    }


    for (auto cycle : cycles){
        int countTrees = 0;
        if (cycle.size() < 3) continue;
        for (int i = 0;i < cycle.size();i++){
            used = vector<char>(n,0);
            if (i == 0) {
                used[cycle[cycle.size() - 1]] = 2;
                used[cycle[i + 1]] = 2;
            }
            else if (i == cycle.size() - 1){
                used[cycle[i-1]] = 2;
                used[cycle[0]] = 2;
            } else{
                used[cycle[i + 1]] = 2;
                used[cycle[i - 1]] = 2;
            }

            edgeCount = -2;
            vertCount = 0;
            flc = false;

            isTree(cycle[i],-1);

            if (edgeCount + 1 == vertCount && flc == 0){
                //cout << "Tree with root in " << cycle[i] << endl;
                countTrees++;
            }

        }
        if (countTrees == cycle.size()){
            cout << "FHTAGN!" << endl;
            return 0;
        }


    }


    cout << "NO" << endl;
    return 0;
}