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
        vector<ll>a(n);
        vector<ll>b(n);
        for (int i = 0;i < n;i++){
            cin >> a[i];
        }
        for (int i = 0;i < n;i++){
            cin >> b[i];
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        ll currA = 0;
        ll currB = 0;
        ll ans = 0;
        for (int i = 0;i < n;i++){
            if (k == 0)
                break;
            if (b[currB] > a[currA]){
                ans += b[currB];
                currA++;
                currB++;
                k--;
            }
            else
                currB++;
        }
        for (int i = currA;i < n;i++){
            ans += a[i];

        }
        cout << ans << endl;
    }
    return 0;
}