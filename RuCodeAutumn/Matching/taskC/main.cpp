#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<bool>>g;

vector<vector<int>>invG;

vector<char>used;
vector<int>match;

vector<vector<int>>resG;

bool dfs(int v){
    if (used[v])
        return false;
    used[v] = 1;
    for (auto to: invG[v]){
        if (match[to] == -1 || dfs(match[v])){
            match[to] = v;
            return true;
        }
    }
    return false;
}

void lastDfs(int v){
    used[v] = 1;
    for (auto to : resG[v]){
        if (!used[to])
            lastDfs(to);
    }
}



int main() {
    int k;
    cin >> k;
    while(k--) {
        int m, n;
        cin >> m >> n;
        g.resize(m);
        for (int i = 0; i < m; i++)
            g[i].resize(n, false);
        for (int i = 0; i < m; i++) {
            int el;
            cin >> el;
            while (el != 0) {
                el--;
                g[i][el] = true;
                cin >> el;
            }
        }

        invG.resize(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!g[i][j])
                    invG[i].push_back(j);
            }
        }
        match.resize(n, -1);
        used.resize(m, 0);
        for (int i = 0; i < m; i++) {
            fill(used.begin(), used.end(), 0);
            dfs(i);
        }

        resG.resize(n + m);
        vector<int> matched(m, -1);
        for (int i = 0; i < n; i++) {
            if (match[i] != -1) {
                matched[match[i]] = i;
                resG[i + m].push_back(match[i]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < invG[i].size(); j++) {
                if (invG[i][j] != matched[i] || matched[i] == -1)
                    resG[i].push_back(invG[i][j] + m);
            }
        }

        used.resize(n + m, 0);
        fill(used.begin(),used.end(),0);
        for (int i = 0; i < matched.size(); i++) {
            if (matched[i] != -1)
                lastDfs(i);
        }


        vector<bool> l(m,false), r(n,false);
        for (int i = 0; i < m + n; i++) {
            if (i < m) {
                if (!used[i])
                    l[i] = true;
            } else {
                if (used[i])
                    r[i - m] = true;
            }
        }

        int rans = 0,lans = 0;

        for (int i = 0;i < l.size();i++) {
            if (l[i])
                lans++;
        }
        for (int i = 0;i < r.size();i++) {
            if (!r[i])
                rans++;
        }


        cout << lans + rans << endl;
        cout << lans << ' ' << rans << endl;
        for (int i = m;i < m + n;i++)
            if (resG[i].size() == 0)
                r[i - m] = false;

        for (int i = 0; i < l.size();i++)
            if (l[i])
                cout << i + 1 << ' ';
        cout << endl;

        for (int i = 0; i < r.size();i++)
            if (!r[i])
                cout << i + 1 << ' ';
        cout << endl;
        cout << endl;

        g.clear();
        invG.clear();
        used.clear();
        match.clear();
        resG.clear();


    }





    return 0;
}