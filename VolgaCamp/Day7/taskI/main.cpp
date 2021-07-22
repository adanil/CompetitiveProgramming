#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
using ll = long long;

vector<char>used;
vector<vector<ll>>g;

bool hasCycle = false;

vector<int>pr;

vector<int>cycle;

int endVert = -1;

void dfs(int v,int p){
    used[v] = 1;
    if (p != -1)
        pr[v] = p;
    for (auto to : g[v]){
        if (!hasCycle && used[to] && to != p && p != -1)
            hasCycle = true;
        if (!used[to])
            dfs(to,v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    g = vector<vector<ll>>(n,vector<ll>(n,0));
    pr.resize(n);
    used.resize(n,0);
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++) {
            int a;
            cin >> g[i][j];
            if (g[i][j] == 0)
                g[i][j] = 10000000000;
            else
                g[i][j] = -1;
        }
    }



    for (int k=0; k<n; ++k)
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                g[i][j] = min (g[i][j], g[i][k] + g[k][j]);



    for (int i = 0;i < n;i++){
        if (g[i][i] < 0)
            hasCycle = true;
    }
    if (hasCycle){
       cout << 1 << endl;
    }
    else{
        cout << 0 << endl;
    }


    return 0;
}