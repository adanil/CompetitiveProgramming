#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int from;
    int to;
    int w;
};

vector<int> par;
vector<int> sz;

int get(int v){
    if (par[v] == v){
        return v;
    }
    par[v] = get(par[v]);
    return par[v];
}

void _union(int v,int u){
    v = get(v);
    u = get(u);
    if (u == v)
        return;
    if (sz[u] > sz[v]){
        swap(u,v);
    }
    par[u] = v;
    sz[v] += sz[u];

}




vector<edge>gr;

int main() {
    int n,m;
    cin >> n >> m;
    par.resize(n);
    sz.resize(n,1);
    for (int i = 0;i < n;i++)
        par[i] = i;
    for (int i = 0;i < m;i++){
        int f,to,w;
        cin >> f >> to >> w;
        f--;to--;
        edge e;
        e.from = f;
        e.to = to;
        e.w = w;
        gr.push_back(e);
    }
    sort(gr.begin(),gr.end(),[](edge a,edge b){return a.w < b.w;});

    int ans = 0;
    for (auto e : gr){
        if (get(e.from) != get(e.to)){
            ans += e.w;
            _union(e.from,e.to);
        }
    }
    cout << ans << endl;

    return 0;
}