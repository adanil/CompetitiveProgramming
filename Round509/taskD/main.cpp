#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

#define INF 1000000
int main() {
    ll n,h;
    cin >> n >> h;
    vector<pair<ll,ll>>a(n);
    for (int i = 0;i < n;i++){
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(),a.end());

    ll answer = 0;

    vector<pair<ll,ll>>pref(n);
    ll diff = 0;
    ll boost = 0;
    pref[0].first = 0;pref[0].second = a[0].second - a[0].first;
    for (int i = 1;i < n;i++){
        diff = a[i].first - a[i - 1].second;
        pref[i].first = diff + pref[i-1].first; pref[i].second = pref[i - 1].second + diff + (a[i].second - a[i].first);
    }


    ll locahH = h;

    ll minF = 0;
    ll minS = 0;
    for (int i = 0;i < n;i++){
        if (i < n - 1) {
            if (pref[i + 1].first - minF > locahH) {
                answer = max(answer, pref[i].second + locahH - pref[i].first - minS);
                auto it = lower_bound(pref.begin(),pref.end(),pair<ll,ll>(pref[i+ 1].first - locahH - minF,-INF));
                if (it == a.end())
                    break;
                minF = it->first;
                minS = it->second- minF;
            }
        }
        else{
            answer = max(answer, pref[i].second + locahH - pref[i].first - minS);
        }

    }

    cout << answer << endl;

    return 0;
}