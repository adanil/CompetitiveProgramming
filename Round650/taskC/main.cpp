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
        ll n,k;
        cin >> n >> k;
        vector<ll>ones;
        string s;
        cin >> s;
        ll ans = 0;
        for (int i = 0;i < n;i++){
            if (s[i] == '1')
                ones.push_back(i);
        }
        if (ones.size() == 0) {
            ans = 0;
            for (int i = 0; i < n; i += (k + 1)) {
                ans++;
            }
        }
        else {
            ll curr = 0;
            ll next = 0;
            for (int i = 0;i < ones.size();i++){
                next = ones[i];
                while(curr+k+1 <= next){
                    ans++;
                    curr += k+1;
                }
                curr = next + k + 1;
            }
            while(curr <= n - 1){
                ans++;
                curr += k+1;
            }
        }
        cout << ans << endl;

    }
    return 0;
}