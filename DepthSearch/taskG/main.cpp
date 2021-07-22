#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <unordered_map>

using namespace std;

vector<char> used;
vector<vector<int>> gt;
int counter = 0;

vector<int> vertexes;
vector<int> enter,out;

vector<char> globalVisited;
unordered_map<int, int> vertexScore;

int t = 0;

void dfs(int v, bool fl = false) {
    used[v] = 1;
    enter[v] = t++;
    if (fl)
        globalVisited[v] = true;
    for (auto to : gt[v]) {
        if (!used[to] && !globalVisited[to]) {
            if (fl)
                dfs(to, fl);
            else
                dfs(to);
        } else
            if (used[to] != 1)
                vertexScore[v] += vertexScore[to];
    }
    out[v] = t++;
    vertexScore[v] += (out[v] - enter[v])/2 + 1;
    used[v] = 2;
}


int main() {
    ios_base::sync_with_stdio(false);
    ifstream fin("firesafe.in");
    ofstream fout("firesafe.out");


    int n, m;
    cin >> n >> m;
    gt = vector<vector<int>>(n);
    used = vector<char>(n, 0);
    enter = vector<int> (n);
    out = vector<int>(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        gt[b].push_back(a);

    }

    for (int i = 0; i < n; i++) {
        vertexes.push_back(i);
        vertexScore[i] = 0;
    }

    vector<int> ans;
    globalVisited = vector<char>(n, false);
    int maxCount = 0;
    int bestVert = -1;
    for (auto v : vertexes) {
        t = 0;
        counter = 0;
        if (used[v] == 0)
            dfs(v);
    }
    //cout << vertexScore.size() << endl;
    while (true) {
        maxCount = -1;
        for (int i = 0;i < n;i++){
            if (vertexScore[i] > maxCount){
                maxCount = vertexScore[i];
                bestVert = i;
            }
        }
        used = vector<char>(n, false);
        ans.push_back(bestVert);
        dfs(bestVert, true);
        vertexes.clear();
        bool stop = true;
        for (int i = 0; i < n; i++) {
            if (globalVisited[i] == 0) {
                stop = false;
            } else
                vertexScore[i] = -1;
        }
        if (stop)
            break;

    }

    cout << ans.size() << endl;
    for (auto a : ans)
        cout << a + 1 << ' ';


    return 0;
}