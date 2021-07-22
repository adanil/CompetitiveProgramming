#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>a(n);
        for (int i = 0;i < n;i++)
            cin >> a[i];
        sort(a.begin(),a.end());

        ll ans = 0;
        ll groupCount = 1;
        ll need = a[0];
        for (int i = 1;i < n;i++){
            if (groupCount >= need){
                ans++;
                groupCount = 1;
                need = a[i];
            }
            else{
                groupCount += 1;
                need = max(need,a[i]);
            }
        }
        if (groupCount >= need)
            ans++;
        cout << ans << endl;
    }
    return 0;
}