#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll>arr(n);
        vector<ll>pref(n);
        string s;
        cin >> s;
        for (int i = 0;i < n;i++) {
            arr[i] = s[i] - 48;
            if (i == 0)
                pref[0] = arr[i];
            else
                pref[i] = pref[i - 1] + arr[i];
        }
        ll ans = (n*(n + 1))/2;
        vector<ll>ng(n + 1);
        vector<ll>izb(n+1);
        for (int i = 0;i < n;i++){
            ll cnt = 0;
            ll currSum = arr[i];
            int j = 0;
            while(i - j - 1 >= 0 && j < arr[i]){
                if (pref[i] - pref[i-j-1] != i - j + 1)
                    ans--;
                j++;
            }
        }
        cout << ans << endl;

    }
    return 0;
}