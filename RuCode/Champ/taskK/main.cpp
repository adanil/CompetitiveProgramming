#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<char> used;
vector<int> tin;
vector<int> currPath;
vector<set<int>>paths;
vector<int> cntVisit;

int t = 0;
int all = 0;

bool inCycle = false;

void dfs(int v,vector<vector<int>>&g,int p){
    if (v == 2)
 //       cout << 'k' << endl;
    used[v] = 1;
    cntVisit[v]++;
    currPath.push_back(v);
    if (cntVisit[v] > all)
        return;
    tin[v] = t++;
    for (auto to : g[v]){
        if (v == 3 && to == 4)
 //           cout << "k2" << endl;
        if (g[v].size() > 1)
            if (to == p) {

                g[v].push_back(to);
                g[v].erase(g[v].begin());
                continue;
                t--;
            }
        if (!used[to]){
            if (inCycle)
                inCycle = false;
            //currPath.push_back(to);
            dfs(to,g,v);
        }
        else if (used[to] == 1){
            //cycle
            if (t - tin[to] <= 3 && !inCycle){ // <= ?
                if (g[to].size() + 1 <  cntVisit[to])
                    continue;
                inCycle = true;
                dfs(to,g,v);
            }
            else if (t - tin[to] <= 3 && inCycle){
                continue;
            }
            else
                continue;
        }
    }
//    cout << "Path in dfs: ";
//    for (int i = 0;i < currPath.size();i++){
//        cout << currPath[i] << ' ';
//    }
//    cout << endl;
    if (!currPath.empty()) {
   //     cout <<  "size: " << currPath.size() << endl;
        if (currPath.size() > all)
            return;
        paths.push_back(set<int>(currPath.begin(), currPath.end()));
    }
    used[v] = 2;
    if (!currPath.empty())
        currPath.erase(currPath.end() - 1);

}


int main() {
    int n,a;
    cin >> n >> a;

    vector<vector<int>>g(n);
    for (int i = 0;i < a;i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        g[f].push_back(t);
        g[t].push_back(f);
    }
    int m,b;
    cin >> m >> b;
    g.resize(m + n);
    for (int i = 0;i < b;i++){
        int f,t;
        cin >> f >> t;
        f--;t--;
        f += n;
        t += n;
        g[f].push_back(t);
        g[t].push_back(f);
    }

    int x,y;
    cin >> x >> y;
    x--;y--;

    g[x].push_back(y + n);
    g[y + n].push_back(x);

    tin.resize(n+m);
    used.resize(n+m);
    cntVisit.resize(n + m);
    all = n + m;


    int ans = 0;
    for (int i = 0;i < n;i++){
        currPath.push_back(i);
        dfs(i,g,-1);
        int vs = 0;
//        for (int j = 0;j < all;j++){
//            if (cntVisit[j] != 0)
//                vs++;
//        }
        ans = max(ans,vs);
        currPath.clear();
        tin.clear();
        fill(tin.begin(),tin.end(),0);
        fill(used.begin(),used.end(),0);
        inCycle = false;
        fill(cntVisit.begin(),cntVisit.end(),0);
        t = 0;

    }
//    cout << "test" << endl;
//
//    for (int i = 0;i < paths.size();i++){
//        for (auto el : paths[i]){
//            cout << el + 1 << ' ';
//        }
//        cout << endl;
//    }

    for (int i = 0;i < paths.size();i++){
        ans = max(ans,(int)paths[i].size());
    }
    cout << ans << endl;



    return 0;
}