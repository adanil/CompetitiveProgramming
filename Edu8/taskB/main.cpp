#include <iostream>
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll ans = 0;
    for (ll i = s.size() - 1;i >= 2;i--){
        ll a = stoi(s.substr(i-1,2));
//        cout << "a: " << a << endl;
        if (a % 4 == 0){
            ans += (i);
        }
//        cout << ans << endl;
    }
    if (s.size() > 1) {
        if (stoi(s.substr(0, 2)) % 4 == 0) {
            ans++;
        }
    }
    for (int i = 0;i < s.size();i++){
        if (stoi(s.substr(i,1)) % 4 == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}