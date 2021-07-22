#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        set<int>s;
        for (int i = 0;i < n;i++) {
            int el;
            cin >> el;
            s.insert(el);
        }

        bool fl = false;
        ll ans = -1;
        for (int k = 1;k < 1025;k++){
            set<int> currS;
            for (auto it = s.begin();it != s.end();it++){
                currS.insert((*it)^k);
            }
            if (currS == s){
                ans = k;
                fl = true;
                break;
            }
        }
        cout << ans << endl;

    }
    return 0;
}