#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;


vector<char>used;
vector<vector<int>>g;
vector<int> path;
map<string,int> mp;

map<int,string>revmp;

void dfs(int v,vector<int> &curr){
    used[v] = true;
    curr.push_back(v);
    if (curr.size() > path.size())
        path = curr;
    for (auto to : g[v]){
        if (!used[to]){
            dfs(to,curr);
            curr.erase(--curr.end());
        }
    }
}

int main() {

    int n;
    cin >> n;

    vector<pair<int,int>>data(n);
    int cnt = 0;
    for (int i = 0;i < n;i++){
        string name,fam;
        cin >> name >> fam;
        if (mp.count(name) == 0){
            mp[name] = cnt++;
            revmp[cnt - 1] = name;
        }
        if (mp.count(fam) == 0){
            mp[fam] = cnt++;
            revmp[cnt - 1] = fam;
        }
        data[i].first = mp[name];
        data[i].second = mp[fam];
    }

//    for (int i = 0;i < n;i++){
//        cout << data[i].first << ' ' << data[i].second << endl;
//    }

    g.resize(cnt);
    for (int i = 0;i < n;i++){
        g[data[i].first].push_back(data[i].second);
    }
    used.resize(cnt,false);

    for (int i = 0;i < cnt;i++){
        used.resize(cnt,false);
        vector<int> curr;
        dfs(i,curr);
    }

    for (int i = 0;i < path.size();i++){
        if (i == 0 || i + 1 == path.size()){
            cout << revmp[path[i]] << ' ';
        }
        else{
            cout << revmp[path[i]] << ", " << revmp[path[i]] << ' ';
        }


    }

}