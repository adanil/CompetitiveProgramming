#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
using ll = long long;


#define INF 1000000000000

int main() {
    ll n,m,d;
    cin >> n >> m >> d;
    set<pair<ll,ll>> a;
    for (int i = 0;i < n;i++){
        pair<ll,ll> el;
        cin >> el.first;
        el.second = i;
        a.insert(el);
    }
    auto it = a.begin();
    ll minToday = a.begin()->first;
    ll indMin = a.begin()->second;
    vector<ll> ans(n);
    ll currDay = 1;
    while(!a.empty()){
        ans[indMin] = currDay;
        a.erase(it);
        it = a.lower_bound({minToday + d + 1,-INF});
        if (it == a.end()) {
            currDay++;
            if (!a.empty()) {
                it = a.begin();
                minToday = it->first;
                indMin = it->second;
            }
        }
        else{
            minToday = it->first;
            indMin = it->second;

        }
    }

    cout << currDay - 1 << endl;
    for (auto el : ans)
        cout << el << ' ';






    return 0;
}