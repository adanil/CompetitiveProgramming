#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using lint = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = std::pair<int, int>;
using vpii = vector<pii>;

namespace solution
{
    // Данные
    int n, m;
    vi t_in, t_out;
    vi depth;
    vvi adj;
    int parent[20][100100];
    std::set<int> apples;
    vi is_apple;
    int subtree_verts;
    // Читаем дерево
    void input()
    {
        cin >> n;
        m = n - 1;
        adj.resize(n + 1);
        for(int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    // посчитаем t_in и t_out
    int dfs_time = 1;
    void dfs(int u){
        t_in[u] = ++dfs_time;
        for (auto to: adj[u]){
            if (!t_in[to])
                parent[0][to] = u, depth[to] = depth[u] + 1, dfs(to);
        }
        t_out[u] = dfs_time;
    }
    // строим таблицу двоичных подъемов
    void build_parent() {
        // parent[2^j][i] ----> "индекс вершины" куда мы попадем из i сделав 2^j шагов
        for (int j = 1; j < 20; j++) {
            for (int i = 1; i <= n; i++) {
                parent[j][i] = parent[j-1][parent[j-1][i]]; // 2^(j-1) шагов из i
            }
        }
    }

    // предподсчет
    void setup()
    {
        is_apple.assign(n + 1,0);
        depth.resize(n + 1);
        depth[0] = -1;
        t_in.resize(n + 1);
        t_out.resize(n + 1);
        dfs(1);
        build_parent();
//        for (int i = 1; i <= n; i++)
//            std::cout << "i = " << i << ", depth = " << depth[i] << std::endl;
    }

    bool in_subtree(int u)
    {
        auto it_left = apples.lower_bound(t_in[u]);
        //auto it_right = apples.lower_bound(t_out[u]);
        // Несторогое неравенство для яблок
        if(it_left != apples.end()) return ((*it_left) <= t_out[u]);
        else return 0;
    }

    int go_up(int u, int steps)
    {
        for(int i = 19; i >= 0; i--) {
            if (parent[i][u] != 0) {
                if (steps & (1 << (i))) u = parent[i][u];
            }
        }
        return u;
    }

    void add(int u)
    {
        int l = -1,r = depth[u];
        int lvert = 0;
        int locu = u;
        while(l + 1 < r){
            int mid = (r - l)/2;
            int to = go_up(locu,mid);
            if (in_subtree(to)) {
                l = depth[to];
                lvert = to;
            }
            else {
                r = depth[to];
                locu = to;
            }
        }
        //cout << "lvert = " << lvert << endl;
        if (in_subtree(u)) {
            apples.insert(t_in[u]);
        }
        else {
            apples.insert(t_in[u]);
            subtree_verts += (depth[u] - depth[lvert]);
        }
       // cout << "subtree_verts = " << subtree_verts << endl;
    }

    void remove(int u)
    {
        apples.erase(t_in[u]);
        if (in_subtree(u))
            return;
        int l = -1,r = depth[u];
        int lvert = 0;
        int locu = u;
        while(l + 1 < r){
            int mid = (r - l)/2;
            int to = go_up(locu,mid);
            if (in_subtree(to)) {
                l = depth[to];
                lvert = to;
            }
            else {
                r = depth[to];
                locu = to;
            }
        }
        subtree_verts -= (depth[u] - depth[lvert]);

    }



    int getAnswer(){
        return (subtree_verts) ? 2*(subtree_verts - 1) : 0;
    }

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    using namespace solution; // (͡° ͜ʖ ͡°)
    input();
    setup();                  // :)
    int q;
    cin >> q;
    while(q--)
    {
        int type;
        cin >> type;
        if(type == 1)
        {
            int u;
            cin >> u;
            add(u);
        }else if(type == 2)
        {
            int u;
            cin >> u;
            remove(u);
        }else
        {
            cout << getAnswer() << "\n"; //◕_◕
        }
    }
}