#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct edge{
    int numb;
    int from;
    int to;
};

int t = 0;

vector<vector<edge>> g;
vector<char> used;
vector<int> tin;
vector<int>tout;
vector<int> fup;
vector<int> ans;
vector<edge> bridges;

int target = 0;



void dfs(int v,int p){
    used[v] = 1;
    tin[v] = t++;
    fup[v] = tin[v];

    for (auto e : g[v]){
        if (e.to == p) continue;

        if (used[e.to]){
            fup[v] = min(fup[v],tin[e.to]);
        }
        else{
            dfs(e.to,v);
            fup[v] = min(fup[v],fup[e.to]);
            if (fup[e.to] > tin[v]) {
                //cout << "bridge " << e.numb << endl;
                if (used[target]) {
                    if (tin[e.to] <= tin[target] && tout[target] <= tout[e.to])
                        ans.push_back(e.numb);
                }
            }

        }
    }
    tout[v] = t++;
}




int main() {
    ifstream fin("inevit.in");
    ofstream fout("inevit.out");
    int n,m;
    fin >> n >> m;
    g = vector<vector<edge>>(n);
    used = vector<char>(n,0);
    tin = vector<int>(n,0);
    tout = vector<int>(n,0);
    fup = vector<int>(n,0);

    target = n-1;

    for (int i = 0;i < m;i++){
        int a,b;
        fin >> a >> b;
        a--;
        b--;
        edge e;
        e.numb = i + 1;
        e.from = a;
        e.to = b;
        g[a].push_back(e);
        edge et;
        et.numb = i+1;
        et.from = b;
        et.to = a;
        g[b].push_back(et);
    }

    dfs(0,-1);



    fout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for (auto a : ans){
        fout << a << ' ';
    }



    return 0;
}