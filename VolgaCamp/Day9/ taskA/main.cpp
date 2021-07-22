#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

using ll = long long;

struct edge{
    int from;
    int to;
    ll wgt;
};

int target;

const ll INF = 1000000000000000000;
vector<char>used;
vector<int>pr;
vector<vector<edge>> g;
ll currMin = INF;
bool fl = false;

void dfs(int v,int p){
    pr[v] = p;
    if (v == target){
        int curr = v;
        while (pr[curr] != -1){
//            for (auto &ed : g[curr]){
//                if (ed.to == pr[curr]) {
//                    ed.wgt += currMin;
////                    break;
//                }
//            }
            for (auto &ed : g[pr[curr]]){
                if (ed.to == curr){
                    ed.wgt -= currMin;
//                    break;
                }
            }
            curr = pr[curr];
        }
        fl = true;
        return;
    }
    used[v] = 1;
    for (auto t : g[v]){
        if (!used[t.to] && t.wgt > 0){
            if (fl)
                return;
            currMin = min(t.wgt,currMin);
            dfs(t.to,v);
        }
    }
}
ll ans = 0;

int main() {
    ifstream fin("flow.in");
    ofstream fout("flow.out");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);
    int n,m;
    fin >> n >> m;
    g.resize(n);
    pr.resize(n);
    used.resize(n,0);
    for (int i = 0;i < m;i++){
        int a,b,c;
        fin >> a >> b >> c;
        edge e;
        a--;b--;
        e.from = a;
        e.to = b;
        e.wgt = c;
        g[e.from].push_back(e);
//        edge revE;
//        revE.from = b;
//        revE.to = a;
//        revE.wgt = 0;
//        g[revE.from].push_back(revE);
    }
    int s;
    fin >> s >> target;
    s--;
    target--;
    while(true){
        dfs(s,-1);
        if (!fl)
            break;
        ans += currMin;
        pr.clear();pr.resize(n);
        used.clear();used.resize(n);
        currMin = INF;
        fl = false;
    }
    fout << ans << endl;



    return 0;
}