#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

vector<vector<int>>g;
vector<char>used;
vector<int>p;

vector<pair<char,int>>vertInfo;
vector<int>cycle;
vector<int>ans;


//0 - не посещен
//1 - в процессе обхода
//2 - вышел
ll iterCount = 0;
void dfs(int v){
    iterCount++;
    if (iterCount > 1e4){
        cout << "gg" << endl;
        return;
    }
    try {
        used[v] = 1;
        int startV = v;
        for (auto to : g[v]) {
            if (!used[to]) {
                p[to] = v;
                dfs(to);
            } else if (used[to] == 1) {
                cycle.push_back(to);
                while (p[v] != to) {
                    cycle.push_back(v);
                    v = p[v];
                }
                cycle.push_back(v);
            }
        }
        used[startV] = 2;
    }
    catch (...){
        cout << "Error" << endl;
    }

}

ll secIter = 0;
void secDfs(int v){
    secIter++;
    if (secIter > 1e4){
        cout << "djask" << endl;
        return;
    }
    try {
        vertInfo[v].first = 1;
        vertInfo[v].second = 0;

        for (auto to : g[v]) {
            if (vertInfo[to].first == 0) {
                secDfs(to);
            }
            if (vertInfo[to].first == 1) {
                ans[v] = vertInfo[to].second + 1;
                vertInfo[v] = {1, ans[v]};
            }
        }
    }
    catch(...){
        cout << "jfakdsjk" << endl;
    }
}



int main() {
    try {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<string, int> mp;
        int n;
        cin >> n;
        string fam, name, q, sonName;
        vector<vector<string>> data(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> fam >> sonName >> q >> q >> name;
            vector<string> tmp = {fam, name, sonName};
            data[i] = (tmp);
            if (mp.count(sonName + '_' + fam) == 0) {
                mp[sonName + '_' + fam] = cnt;
                cnt++;
            }
        }
        g.resize(mp.size());
        for (int i = 0; i < data.size(); i++) {
            fam = data[i][0];
            name = data[i][1];
            sonName = data[i][2];
            if (mp.count(sonName + '_' + fam) != 0 && mp.count(name + '_' + fam) != 0)
                g[mp[sonName + '_' + fam]].push_back(mp[name + '_' + fam]);
        }
        n = mp.size();

//    for (auto it = mp.begin();it != mp.end();it++){
//        cout << it->first << ' ' << it->second << endl;
//    }

        used.resize(n, 0);
        p.resize(n, -1);
        vertInfo.resize(n, {0, -1});
        ans.resize(n, 0);
        for (int i = 0; i < n; i++) {
            if (!used.at(i)) {
                dfs(i);
                for (int j = 0; j < cycle.size(); j++) {
                    vertInfo.at(cycle.at(j)) = {1, cycle.size()};
                    ans.at(cycle.at(j)) = cycle.size();
                }
                cycle.clear();
            }
        }
        fill(used.begin(), used.end(), 0);

        for (int i = 0; i < n; i++) {
            if (g.at(i).size() == 0) {
                vertInfo.at(i) = {1, 1};
                ans.at(i) = 1;
            }
        }


        for (int i = 0; i < n; i++) {
            if (vertInfo.at(i).first == 0) {
                secDfs(i);
            }
        }

        cout << *max_element(ans.begin(), ans.end()) << endl;


    }
    catch (...){
        cout << "error" << endl;
    }
    return 0;
}