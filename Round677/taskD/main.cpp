#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

struct mst {
    int cnt;
    vector<int> houses;
    ll color;

    mst(int cnt, vector<int> houses, ll color) : cnt(cnt), houses(houses), color(color) {}
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        map<ll, vector<int>> mp;
        vector<mst> vc;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]].push_back(i);
            mx = max(mx, (int) mp[a[i]].size());
        }


        int k = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vc.emplace_back(mst(it->second.size(), it->second, it->first));
        }

        sort(vc.begin(), vc.end(), [](mst a, mst b) {
            return a.cnt > b.cnt;
        });

        vector<pair<int, int>> ans;
        if (mx == n){
            cout << "NO" << endl;
        }
        else{
            int k = 0;
            int q = 0;
            while(vc[q].cnt == 0)
                q++;
            int curr = vc[q].houses[vc[q].cnt - 1];
            int currCol = vc[q].color;
            vc[q].cnt--;
            while(k != n - 1){
                q = 0;
                while(vc[q].cnt == 0 || currCol == vc[q].color)
                    q++;
                for (int i = vc[q].cnt;i > 0;i--){
                    ans.emplace_back(curr + 1,vc[q].houses[i - 1] + 1);
                    vc[q].cnt--;
                    k++;
                }
                curr = vc[q].houses[vc[q].cnt];
                currCol = vc[q].color;
            }


            cout << "YES" << endl;
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i].first << ' ' << ans[i].second << endl;

        }

    }
    return 0;
}