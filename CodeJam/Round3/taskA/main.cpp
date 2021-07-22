#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;

const ll INF = 100000000000;

int main() {
    ll t;
    cin >> t;
    ll tcopy = t;
    while(t--){
        ll x,y;
        string path;
        cin >> x >> y;
        cin >> path;
        vector<ll>myTime(path.size());
        ll ctTime = 0;
        vector<ll>catTime(path.size());
        vector<pair<ll,ll>>catStep(path.size());
        for (ll i = 0;i < path.size();i++){
            if (path[i] == 'S')
                y--;
            else if (path[i] == 'N')
                y++;
            else if (path[i] == 'E')
                x++;
            else
                x--;
            catTime[i] = ++ctTime;
            catStep[i] = pair<ll,ll>(x,y);
        }
        for (ll i = 0;i < path.size();i++){
            ll myTm = 0;
            myTm = abs(catStep[i].first) + abs(catStep[i].second);
            myTime[i] = myTm;
        }
        ll ans = INF;
        for (ll i = 0;i < path.size();i++){
            if (myTime[i] <= catTime[i])
                ans = min(ans,catTime[i]);
        }
        if (ans == INF)
            cout << "Case #" <<tcopy - t << ": " << "IMPOSSIBLE" << endl;
        else
            cout << "Case #" <<tcopy - t << ": " << ans << endl;

    }

    return 0;
}