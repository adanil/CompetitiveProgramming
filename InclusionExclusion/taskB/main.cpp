#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void dfs(int v){

}

int main() {
    int n;
    cin >> n;
    vector<vector<int>>g(n,vector<int>());
    for (int i = 0;i < n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
    }
    int m;
    cin >> m;
    vector<pair<int,int>>bl(m);
    for (int i = 0;i < m;i++){
        cin >> bl[i].first >> bl[i].second;
    }
    return 0;
}