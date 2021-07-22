#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

vector<vector<int>>g;
vector<char> used;
stack<int> ans;

bool isCycle = false;


void dfs(int v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to])
            dfs(to);
        else if (used[to] == 1)
            isCycle = true;
    }
    ans.push(v);
    used[v] = 2;
}

int main() {
    ios_base::sync_with_stdio(false);

    ifstream fin("topsort.in");
    ofstream fout("topsort.out");

    int n,m;
    fin >> n >> m;
    g = vector<vector<int>>(n);
    used = vector<char>(n,0);

    for (int i = 0;i < m;i++){
        int a,b;
        fin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }


    for (int i = 0;i < n;i++){
        if (!used[i])
            dfs(i);

        if (isCycle){
            fout << -1 << endl;
            return 0;
        }

    }

    while (!ans.empty()) {
        fout << ans.top() + 1 << ' ';
        ans.pop();
    }
    return 0;
}