#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

using ll = long long;
const ll INF = 99999999999;

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<ll>p(n);
    for (auto &el : p){
        cin >> el;
    }
    map<ll,ll>zp;
    for (int i = 0;i < n;i++){
        zp[p[i]] = i;
    }

    vector<set<int>>colors(n,set<int>());
    vector<pair<ll,ll>>prg(m);
    for (int i = 0;i < m;i++){
        cin >> prg[i].first >> prg[i].second;
        prg[i].first = zp[prg[i].first];
        prg[i].second = zp[prg[i].second];
        if (prg[i].first > prg[i].second)
            swap(prg[i].first,prg[i].second);
    }
    vector<pair<ll,ll>>pr;
    for (auto it = prg.begin();it != prg.end();it++){
        pr.push_back({it->first,it->second});
    }

    sort(pr.begin(),pr.end());
    pr.erase(unique(pr.begin(),pr.end()),pr.end());



    m = pr.size();

    for (int i = 0;i < m;i++){
        colors[pr[i].first].insert(i);
        colors[pr[i].second].insert(i);
    }

    ll l,r;
    l = r = n - 1;

    ll ans = n;

    set<int>myColors;
    while(l >= 0){
        for (auto el : colors[l]){
            if (myColors.count(el) == 0)
                myColors.insert(el);
            else{
                r = min(r,pr[el].second - 1);
            }
        }
        ans += (r - l);
        l--;
    }
    cout << ans << endl;

    return 0;
}
