#include <iostream>
#include <vector>

using namespace std;
using ld = long double;
using ll = long long;
const ll INF = 200000 * 1000000000000 + 1;

struct edge{
    ll a;
    ll b;
    ll cost;
};

int main() {
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    s--;
    vector<edge>e(m);
    for (int i = 0;i < m;i++){
        ll a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        edge eg;
        eg.a = a;
        eg.b = b;
        eg.cost = w;
        e[i] = eg;
    }


    vector<ll> d (n, INF);
    d[s] = 0;
    for (;;) {
        bool any = false;
        for (int j=0; j<m; ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + e[j].cost) {
                    d[e[j].b] = d[e[j].a] + e[j].cost;
                    any = true;
                }
        if (!any)  break;
    }

    if (d[t-1] == INF)
        cout << 1000000000000000000 << endl;
    else
        cout << d[t-1] << endl;


    return 0;
}