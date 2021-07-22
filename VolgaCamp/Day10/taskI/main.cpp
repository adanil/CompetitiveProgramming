#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<string,set<string>>mp;
        for (int i = 0;i < n;i++) {
            string attr, ctg;
            cin >> attr >> ctg;
            mp[ctg].insert(attr);
        }
        ll ans = 1;
        for (auto it = mp.begin();it != mp.end();it++){
            ans *= it->second.size() + 1;
        }
        cout << ans - 1 << endl;


    }
    return 0;
}