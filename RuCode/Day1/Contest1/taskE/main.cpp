#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000; // значение "бесконечность"


struct edge{
    int from;
    int to;
    int w;
};

vector<int> par;
vector<int> sz;
vector<int>maxWidth;

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

    int n,m,k;
    cin >> n >> m >> k;
    par.resize(n);
    sz.resize(n,1);
    maxWidth.resize(n,-1);
    for (int i = 0;i < m;i++){
        edge e;
        int a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        e.from = a;
        e.to = b;
        e.w = w;
        gr.push_back(e);
    }

    vector<vector<int>> dp(n,vector<int>(n,INF));

    sort(gr.begin(),gr.end(),[](edge a,edge b){return a.w > b.w;});

    int ans = 0;
    int curMax = 0;
    for (auto e : gr){
        if (get(e.from) != get(e.to)){
            dp[e.from][e.to] =
            ans += e.w;
            dp[e.from][e.to] = e.w;
            dp[e.to][e.from] = e.w;
            _union(e.from,e.to);
        }
    }



    for (int i = 0;i < k;i++){

    }

    cout << ans << endl;

    return 0;
}