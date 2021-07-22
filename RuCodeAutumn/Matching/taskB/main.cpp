#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int>>g;
vector<char>used;

vector<bool>firstMatch;

void dfs(int v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to])
            dfs(to);
    }
}

int main() {
    int n,m;
    cin >> m >> n;
    g.resize(m + n);
    for (int i = 0;i < m;i++){
        int k;
        cin >> k;
        while(k--){
            int el;
            cin >> el;
            el--;
            g[i].push_back(el + m);
        }
    }
    firstMatch.resize(m);
    for (int i = 0;i < m;i++){
        int el;
        cin >> el;
        if (el != 0){
            el--;
            g[el + m].push_back(i);
            g[i].erase(find(g[i].begin(),g[i].end(),el + m));
            firstMatch[i] = true;
        }
    }

    used.resize(n + m,0);
    for (int i = 0;i < m;i++){
        if (!firstMatch[i])
            dfs(i);
    }

    int ans = 0;
    vector<int>rplus,lminus;
    for (int i = 0; i < used.size();i++){
        if (i < m){
            if (!used[i])
                lminus.push_back(i+1);
        }
        else{
            if (used[i])
                rplus.push_back(i + 1 - m);
        }
    }
    cout << rplus.size() + lminus.size() << endl;
    cout << lminus.size() << ' ';
    for (auto el : lminus)
        cout << el << ' ';
    cout << endl;
    cout << rplus.size() << ' ';
    for (auto el : rplus)
        cout << el << ' ';


    return 0;
}