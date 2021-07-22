#include <iostream>
#include <vector>
#include <string>

using ll = long long;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        string ans;
        ans += s[0]; ans += s[1];
        for (int i = 2;i < s.size();i++){
            if (i % 2 != 0)
                ans += s[i];
        }
//        ans += s[s.size() - 1];
        cout << ans << endl;

    }
    return 0;
}