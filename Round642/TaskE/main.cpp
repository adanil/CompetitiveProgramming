#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll>pref(n);
        vector<ll>suf(n);
        vector<ll>dst;
        ll ans = 0;
        ll currPref = 0;
        for (int i = 0;i < n;i++){
            pref[i] = currPref;
            if (s[i] == '1')
                currPref++;
        }
        ll currSuf = 0;
        for (int i = n - 1;i >= 0;i--){
            suf[i] = currSuf;
            if (s[i] == '1')
                currSuf++;
        }
        ll prev = -1;
        for (int i = 0;i < n;i++){
            if (s[i] == '1')
                dst.push_back(i);

        }

        for (int i = 1;i < dst.size();i++){
            if (dst[i] - dst[i - 1] != k) {
                ans++;
                dst[i - 1] = dst[i];
            }

        }
        cout << ans << endl;

    }
    return 0;
}