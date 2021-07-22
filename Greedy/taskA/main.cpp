#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

struct task{
    ll d;
    ll c;
    ll id;
    vector<ll>pred;
};

vector<ll> order;

vector<char>used;
vector<vector<ll>>g;
vector<task>tasks;
vector<task>unsort;

vector<ll>ans;

void dfs (int v) {
    used[v] = 1;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
        else if (used[to] == 1) {
            cout << "NO" << endl;
            exit(0);
        }

    }
    ans.push_back (v);
    used[v] = 2;
}

void topological_sort() {
    ll n = tasks.size();
    for (int i=0; i<n; ++i)
        used[i] = false;
    ans.clear();
    for (auto i : order)
        if (!used[i])
            dfs (i);
//    reverse (ans.begin(), ans.end());
}

int main() {
    ll n;
    cin >> n;
    g.resize(n);
    tasks.resize(n);
    unsort.resize(n);
    used.resize(n);
    for (int i = 0;i < n;i++){
        ll d,c,r;
        cin >> d >> c >> r;
        tasks[i].d = d;
        tasks[i].c = c;
        tasks[i].id = i;
        unsort[i].d = d;
        unsort[i].c = c;
        for (int j = 0;j < r;j++){
            ll el;
            cin >> el;
            el--;
            tasks[i].pred.push_back(el);
        }
    }
    for (int i = 0;i < n;i++){
        sort(tasks[i].pred.begin(),tasks[i].pred.end(),[](ll a,ll b){
            return tasks[a].d < tasks[b].d;
        });
        for (int j = 0;j < tasks[i].pred.size();j++)
            g[i].push_back(tasks[i].pred[j]);
    }


    sort(tasks.begin(),tasks.end(),[](task a,task b){return a.d < b.d;});
    for (auto t:tasks){
        order.push_back(t.id);
    }


    topological_sort();

    int ta = 0;
    for (auto el: ans) {
        if (ta + unsort[el].c <= unsort[el].d)
            ta += unsort[el].c;
        else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (auto el:ans)
        cout << el + 1 << ' ';



    return 0;

}