#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


const int INF = 1000000000;


ll Prim(int n,vector<vector<ll>>gr){
    vector<bool> used (n);
    vector<ll> dist(n,INF);
    dist[0] = 0;
    ll ans = 0;
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        if (v == -1)
            break;
        ans += dist[v];
        used[v] = true;


        for (int to=0; to<n; ++to)
            if (gr[v][to] < dist[to]) {
                dist[to] = gr[v][to];
            }
    }
    return ans;

}

int main() {
    int n;
    cin >> n;
    vector<vector<ll>>gr(n+1,vector<ll>(n+1,INF));
    vector<ll> price(n);
    for (int i = 0;i < n;i++){
        for (int j = 0;j < n;j++) {
            cin >> gr[i][j];
            if (i == j)
                gr[i][j] = INF;
        }
    }
    for (int i = 0;i < n;i++){
        cin >> price[i];
    }
    vector<ll> ans;
    for (int i = 0;i < n;i++){
        gr[i][n] = price[i];
        gr[n][i] = price[i];
    }
//    cout << *min_element(ans.begin(),ans.end()) << endl;
    cout << Prim(n+1,gr) << endl;

    return 0;
}