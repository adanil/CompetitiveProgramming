#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
const int INF = 1000000000;
using ll = long long;

vector<int> dijkstra(int v){

}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n,m,a,b,c;
        cin >> n >> m >> a >> b >> c;
        a--;
        b--;
        c--;
        vector<vector<pair<int,int>>>g(n);
        vector<int>price(m);
        for (int i = 0;i < m;i++)
            cin >> price[i];
        for (int i = 0;i < m;i++){
            int f,to;
            cin >> f >> to;
            f--;to--;
            g[f].push_back(pair<int,int>(to,1));
            g[to].push_back(pair<int,int>(f,1));
        }


        ////
        vector<int> dOne (n, INF),  pOne (n);
        dOne[a] = 0;
        vector<char> uOne (n);
        for (int i=0; i<n; ++i) {
            int v = -1;
            for (int j=0; j<n; ++j)
                if (!uOne[j] && (v == -1 || dOne[j] < dOne[v]))
                    v = j;
            if (dOne[v] == INF)
                break;
            uOne[v] = true;

            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                        len = g[v][j].second;
                if (dOne[v] + len < dOne[to]) {
                    dOne[to] = dOne[v] + len;
                    pOne[to] = v;
                }
            }
        }

        vector<int> pathOne;
        for (int v=b; v!=a; v=pOne[v])
            pathOne.push_back (v);
        pathOne.push_back (a);
        reverse (pathOne.begin(), pathOne.end());


        vector<int> d (n, INF),  p (n);
        d[b] = 0;
        vector<char> u (n);
        for (int i=0; i<n; ++i) {
            int v = -1;
            for (int j=0; j<n; ++j)
                if (!u[j] && (v == -1 || d[j] < d[v]))
                    v = j;
            if (d[v] == INF)
                break;
            u[v] = true;

            for (size_t j=0; j<g[v].size(); ++j) {
                int to = g[v][j].first,
                        len = g[v][j].second;
                if (d[v] + len < d[to]) {
                    d[to] = d[v] + len;
                    p[to] = v;
                }
            }
        }

        vector<int> path;
        for (int v=c; v!=b; v=p[v])
            path.push_back (v);
        reverse (path.begin(), path.end());

        vector<int> pathAll = pathOne;
        pathAll.insert(pathAll.end(),path.begin(),path.end());

        sort(price.begin(),price.end());

        map<int,int> mp;
        for (auto el : pathAll){
            ++mp[el];
        }
        vector<int>dop;
        for (auto el: mp){
            dop.push_back(el.second);
        }
        sort(dop.rbegin(),dop.rend());

        ll ans = 0;
        for (int i = 0;i < dop.size() - 1;i++){
            ans += price[i] * dop[i];
        }
        cout << ans << endl;


    }
    return 0;
}