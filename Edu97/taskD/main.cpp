#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using ll = long long;
using namespace std;
const int sf = 300;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll q;
    cin >> q;
    while(q--){
       int n;
       cin >> n;
       vector<int>a(n);
       for (auto &el : a){
           cin >> el;
       }
       int prevLevel = 1;
       int ans = 0;
       int i = 1;
       int currLevel = 0;
       int lv = 0;
       while(i + 1 < n){
           while(prevLevel > 0) {
               while (i + 1 < n && a[i] < a[i + 1]) {
                   i++;
                   currLevel++;
               }
               if (i + 1 == n)
                   break;
               currLevel++;
               prevLevel--;
               i++;
           }
           ans++;
           lv++;
           if (i + 1 != n) {
               prevLevel = currLevel;
               currLevel = 0;
           }
       }
       if ((a[n - 1] < a[n - 2] && prevLevel == 0 )|| lv == 0){
           ans++;
       }
       cout << ans << endl;
    }
    return 0;
}