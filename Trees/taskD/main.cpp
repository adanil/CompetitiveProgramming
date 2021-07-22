#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using ll = long long;

ll lg = 0;
ll timer;

vector<vector<ll>>g;
//vector<char>used;
vector<vector<ll>>up;
vector<ll>tin;
vector<ll>tout;



void dfs(int v,int prev = 0){
    tin[v] = ++timer;
    up[v][0] = prev;
    for (int i = 1;i < lg;i++){
        up[v][i] = up[up[v][i-1]][i - 1];
    }
    for (auto to : g[v]){
        if (to != prev)
            dfs(to,v);
    }
    tout[v] = ++timer;

}


bool upper(ll a,ll b){
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

ll lca(ll a, ll b){
    if (upper(a,b)) return a;
    if (upper(b,a)) return b;
    for (ll i = lg;i >= 0;i--){
        if (!upper(up[a][i],b))
            a = up[a][i];
    }
    return up[a][0];
}



int main() {
    ifstream fin("lca.in");
    ofstream fout("lca.out");
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fout.tie(NULL);
    ll k;
    fin >> k;
    g.resize(k);
//    used.resize(k);
    ll countVert = 1;
    while(k--){
        string s;
        fin >> s;
        if (s == "ADD"){
            ll from,to;
            countVert++;
            fin >> from >> to;
            from--;to--;
            g[from].push_back(to);
            g[to].push_back(from);
        }
        else{
            ll a,b;
            fin >> a >> b;
            a--;
            b--;
//            fill(used.begin(),used.end(),false);
            timer = 0;
            lg = 0;
            tin.resize(countVert);
            tout.resize(countVert);
            while ((lg<<1) <= countVert) lg++;
            up.resize(countVert);
            for(ll i = 0;i < countVert;i++)
                up[i].resize(lg+1);

            dfs(0);
            fout << lca(a,b) + 1 << endl;

        }
    }
    return 0;
}