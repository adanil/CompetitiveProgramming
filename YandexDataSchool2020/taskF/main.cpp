#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <set>

using namespace std;
using ll = long long;

struct door{
    ll from;
    ll to;
    ll type;
    vector<ll> keys;
    const bool operator<(const door& b){
        return this->from < b.from;
    }
};

set<door> q;

vector<char> used;
vector<vector<door>>g;
vector<vector<ll>>roomsKeys;
unordered_set<ll> myKeys;

bool flag = true;

void dfs(int v){
    used[v] = true;
    myKeys.insert(roomsKeys[v].begin(),roomsKeys[v].end());
    while(flag) {
        for (auto rm : g[v]) {
            if (myKeys.count(rm.type) == 0)
                q.insert(rm);
            if (!used[rm.to] && myKeys.count(rm.type) != 0) {
                dfs(rm.to);
            }
        }
        flag = false;
        auto it = q.begin();
        while (it != q.end()){
            if (myKeys.count(it->type) != 0){
                v = it->to;
                q.erase(it);
                dfs(v);
                flag = true;
                break;
            }
            else
                it++;
        }
    }
}






int main() {
    ll n;
    cin >> n;
    used.resize(n);
    g.resize(n);
    roomsKeys.resize(n);
    for (int i = 0;i < n;i++){
        ll q,m;
        cin >> q >> m;
        vector<ll>keys(q);
        for (int j = 0;j < q;j++){
            cin >> keys[j];
            keys[j]--;
        }
        roomsKeys[i] = keys;
        for (ll k = 0;k < m;k++){
            door dr;
            dr.from = i;
            cin >> dr.to >> dr.type;
            dr.type--;
            dr.to--;
            g[i].push_back(dr);
        }
    }
    dfs(0);
    if (used[n-1] != 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}