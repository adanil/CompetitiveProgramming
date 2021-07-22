#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>


using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    ll copyt = t;
    while(t--){
        ll u;
        cin >> u;
        vector<pair<ll,string>>a(10000);
        for (ll i = 0;i < 10000;i++){
            cin >> a[i].first >> a[i].second;
//            cout << a[i].first << ' ' << a[i].second << endl;
        }
        sort(a.begin(),a.end());
        map<ll,char>ans;

        set<char> ch;
        set<char>used;

        for (ll i = 0;i < 10000;i++){
            for (ll j = 0;j < a[i].second.size();j++)
                ch.insert(a[i].second[j]);
            if (a[i].second.size() != 1)
                continue;

//            cout << a[i].second[0] << endl;
//            cout << ch.size() << endl;
            if (a[i].first == 1) {
                ans[1] = a[i].second[0];
                used.insert(a[i].second[0]);
            }
            else{
                bool fl = true;
                for (ll j = 1;j < a[i].first;j++) {
                    if (ans[j] == a[i].second[0])
                        fl = false;
                }
                if (fl) {
                    ans[a[i].first] = a[i].second[0];
                    used.insert(a[i].second[0]);
                }

            }
        }
        for (auto el: ch){
//            cout << el << endl;
            if (used.find(el) == used.end())
                ans[0] = el;
        }
        cout << "Case #" << copyt - t << ": ";
        for (ll i = 0;i < 10;i++)
            cout << ans[i];
        cout << endl;

    }
    return 0;
}