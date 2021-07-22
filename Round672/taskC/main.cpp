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
       int n,q;
       cin >> n >> q;
       vector<ll>a(n);
       ll ans = 0;
       ll prev = -1;
       char act = 1; //1 - +    0 - -
       for (int i = 0;i < n;i++){
           cin >> a[i];
           if (prev == -1){
               ans += a[i];
               act = 1;
               prev = a[i];
           }
           else{
               if (act == 1 && a[i] > prev){
                   ans -= prev;
                   ans += a[i];
                   prev = a[i];
               }
               else if (act == 1 && a[i] < prev){
                   ans -= a[i];
                   prev = a[i];
                   act = 0;
               }
               else if (act == 0 && a[i] < prev){
                   ans += prev;
                   ans -= a[i];
                   prev = a[i];
               }
               else if (act == 0 && a[i] > prev){
                   ans += a[i];
                   prev = a[i];
                   act = 1;
               }
           }
       }
       if (act == 0)
           ans += prev;
       cout << ans << endl;

    }
    return 0;
}