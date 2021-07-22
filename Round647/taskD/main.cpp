#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;
using ll = long long;

vector<vector<ll>>g;

vector<ll>theme;

vector<char> used;
const ll INF = 100000000000;

map<ll,ll> writed;

int main() {
    ll n,m;
    cin >> n >> m;
    g.resize(n);
    used.resize(n);
    for (int i = 0;i < m;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0;i < n;i++){
        ll el;
        cin >> el;
        theme.push_back(el);
    }

    ll currTheme = theme[0];
    ll currBlog = 0;
    for (int i = 0;i < n;i++){
        if (theme[i] < currTheme){
            currTheme = theme[i];
            currBlog = i;
        }
    }

    vector<ll> ans;
    while (ans.size() != n){
        ans.push_back(currBlog + 1);
        if (ans.size() == n)
            break;
        used[currBlog] = 1;
//        set<ll>writed;
        writed[currBlog] = currTheme;
//        for (auto el : g[currBlog]) {
//            if (used[el])
//                neighbors.insert(theme[el]);
//        }


        currTheme = INF;

        for (int i = 0;i < n;i++){
            if (theme[i] < currTheme && !used[i]){
                bool fl = true;
                for (auto el : g[i]){
                    if (writed[el] == theme[i]) {
                        fl = false;
                        break;
                    }
                }
                if (fl) {
                    currTheme = theme[i];
                    currBlog = i;
                }
            }
        }
        if (currTheme == INF){
            cout << -1 << endl;
            return 0;
        }
    }
    for (auto el : ans)
        cout << el << ' ';
    cout << endl;






    return 0;
}