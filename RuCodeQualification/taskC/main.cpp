#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;

ll getZipCoord(vector<ll> &coord,ll value){
    return lower_bound(coord.begin(),coord.end(),value) - coord.begin();
}


int main() {
    ll r;
    cin >> r;
    ll m;
    cin >> m;
    vector<ll>coord(m * 2 + 1);
    vector<pair<ll,ll>>station(m);
    for (int i = 0;i < m;i++){
        cin >> station[i].first >> station[i].second;
        coord[i*2] = station[i].first; coord[i*2 + 1] = station[i].second;
    }
    coord[m*2] = r;

    sort(station.begin(),station.end());

    ll rightBorder = station[0].second;
    ll ans = station[0].first;
    for (int i = 1;i < m;i++){
        if (station[i].first > rightBorder)
            ans = max(ans,station[i].first - rightBorder);
        rightBorder = max(rightBorder,station[i].second);
    }

    if (r > rightBorder)
        ans = max(ans,r - rightBorder);
    cout << ans << endl;

    return 0;
}