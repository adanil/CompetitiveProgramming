#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using ll = long long;

vector<vector<ll>>g;
vector<char>used;
vector<char>lux;
vector<ll>d;

void bfs(ll v){
    queue<ll> q;
    used[v] = 1;
    d[v] = 0;
    q.push(v);
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (int neighbor: g[cur]) {
            if (!used[neighbor]) {
                q.push(neighbor);
                used[neighbor] = 1;
                d[neighbor] = d[cur] + 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    lux.resize(n,0);
    used.resize(n,0);
    d.resize(n,-1);
    g.resize(n);
    vector<ll>act;
    for (int i = 0;i < n;i++){
        int el;
        cin >> el;
        if (el) {
            lux[i] = el;
            act.push_back(i);
        }
    }
    for (int i = 0;i < n - 1;i++){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = 0;
    if (act.size() == 0){
        cout << ans << endl;
        return 0;
    }
    bfs(act[0]);

    ll firstMax = 0;
    ll vert = -1;
    for (int i = 0;i < act.size();i++){
        if (d[act[i]] > firstMax){
            firstMax = d[act[i]];
            vert = act[i];
        }
    }
    fill(used.begin(),used.end(),0);
    fill(d.begin(),d.end(),-1);
    if (vert == - 1){
        cout << 0 << endl;
        return 0;
    }

    bfs(vert);

    for (int i = 0;i < act.size();i++){
        if (d[act[i]] > firstMax){
            firstMax = d[act[i]];
        }
    }
    if (firstMax % 2 != 0){
        cout << firstMax/2 + 1 << endl;
    }
    else
        cout << firstMax/2 << endl;
    return 0;
}