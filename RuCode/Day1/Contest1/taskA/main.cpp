#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<vector<int>>g;


vector<int> par;
vector<int> sz;


int get(int v){
    if (par[v] == v){
        return v;
    }

    return get(par[v]);
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

int main() {
    int n,m,k;
    cin >> n >> m >> k;
    for (int i = 0;i < n;i++){
        par[i] = i;
    }
    sz.resize(n,1);
    g.resize(n);
    for (int i = 0;i < m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        _union(a,b);
    }
    for (int i = 0;i < k;i++){
        string s;
        int a,b;
        cin >> s >> a >> b;
        a--;b--;
        if (s == "ask"){
            if (get(a) == get(b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else{

        }

    }

    return 0;
}