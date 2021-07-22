#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(nullptr);
    ll maxq = 0;
    string s;
    ll n,k;
    ll kc;
    cin >> n >> k;
    cin >> s;
    kc = k;
    for (int i = 0;i < n;i++){
        maxq += max((ll)'z' - s[i],(ll)s[i] - 'a');
    }
    if (maxq < k)
        cout << -1 << endl;
    else{
        string ans;
        for (int i = 0;i < n;i++){
            int t = max(min(k,(ll)'z' - s[i]),min(k,(ll)s[i] - 'a'));
            if (s[i] + t <= 'z')
                ans.push_back(s[i] + t);
            else
                ans.push_back(s[i] - t);
            k -= t;
        }
        cout << ans << endl;
//        ll check = 0;
//        for (int i = 0;i < n;i++){
//            check += ans[i] - s[i];
//        }
//        if (check == kc)
//            cout << "OK" << endl;
//        else
//            cout << "ERROR" << endl;
    }


    return 0;
}