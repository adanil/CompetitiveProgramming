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
        if (!used[to])
            dfs(to,v);
        else if (!hasCycle && used[to] && to != p){
            hasCycle = true;
            endVert = to;
            int copyv = v;
            while(pr[copyv] != to){
                cycle.push_back(copyv);
                copyv = pr[copyv];
            }
            cycle.push_back(copyv);cycle.push_back(to);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin >> n >> m;
    g.resize(n);
    pr.resize(n);
    used.resize(n,0);
    ll ans = 0;
    for (int i = 0;i < m;i++){
        ll from,to;
        cin >> from >> to;
        from--;
        to--;
        g[from].push_back(to);
        g[to].push_back(from);
    }

    for (int i = 0;i < n;i++){
        if (!used[i]) {
            dfs(i,-1);
            ans++;
        }
    }
    if (hasCycle){
        cout << "Yes" << endl;
        cout << cycle.size() << endl;
        for (int i = 0;i < cycle.size();i++){
            cout << cycle[i] + 1 << ' ';
        }
        cout << endl;
    }
    else{
        cout << "No" << endl;
    }


    return 0;
}