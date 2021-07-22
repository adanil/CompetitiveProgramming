#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;




vector<char> used;
vector<int> p;

int cycle_start,cycle_end;

bool found = false;

void dfs(int v,vector<vector<int>> &g){
    used[v] = 1;
    for (auto it = g[v].begin();it != g[v].end();it++){
        if (used[*it] == 0) {
            p[*it] = v;
            dfs(*it, g);
        }
        else if (used[*it] == 1){
            //Cycle found
            found = true;
            cycle_start = *it;
            cycle_end = v;
        }
    }
    used[v] = 2;
}

int main() {
    ifstream fin("cycle2.in");
    ofstream fout("cycle2.out");
    int n,m;
    fin >> n >> m;

    vector<vector<int>> g(n);
    used = vector<char>(n,0);
    p = vector<int>(n,-1);
    for (int i = 0; i < m;i++){
        int a,b;
        fin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }

    for (int i = 0;i < n;i++){
        dfs(i,g);
        if (found) {
            vector<int>cycle;
            fout << "YES" << endl;
            while (cycle_end != cycle_start){
                cycle.push_back(cycle_end + 1);
                cycle_end = p[cycle_end];
            }
            cycle.push_back(cycle_start + 1);
            for (int j = cycle.size()-1;j >=0;j--)
                fout << cycle[j] << ' ';


            break;
        }
    }

    if (!found)
        fout << "NO" << endl;

    return 0;
}