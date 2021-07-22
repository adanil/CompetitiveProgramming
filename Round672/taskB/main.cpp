#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        vector<ll>leftBit(40,0);
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0;i < n;i++){
            ull el;
            cin >> el;
            int bit = 0;
            int q = 0;
            while (el > 0){
                if ((el & 1) != 0)
                    bit = q;
                q++;
                el >>= 1;
            }
            ans += leftBit[bit];
            leftBit[bit]++;
        }
        cout << ans << endl;

    }
    return 0;
}