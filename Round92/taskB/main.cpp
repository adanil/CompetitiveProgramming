#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
using ll = long long;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm (ll a, ll b) {
    return a / gcd (a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
       int n,k,z;
       cin >> n >> k >> z;
       vector<int>a(n);
       vector<ll>pref(n);
       int maxS = -1;
       int maxInd = -1;
       int maxEl = -1;
       int maxIndEl = -1;
       for (int i = 0;i < n;i++){
           int el;
           cin >> el;
           a[i] = el;
           if (i == 0)
               pref[i] = el;
           else
               pref[i] = pref[i - 1] + el;
           if (a[i] > maxEl && i <= k){
               maxEl = a[i];
               maxIndEl = i;
           }
           if (i > 0 && i <= k){
               if (a[i - 1] + a[i] > maxS)
                   maxInd = i;
               maxS = max(maxS,a[i - 1] + a[i]);
           }
       }
       ll ans = pref[k];
       bool fl = false;
       int tmp = -1;
       int q = -1;
       for (int i = 1;i <= z;i++){
           if (k - 2*i >= maxInd)
               ans = max(ans,i * maxS + pref[k - 2*i]);
           if (k - 2*i == maxInd - 1) {
               fl = true;
               tmp = k - 2*(i - 1) - 1;
               q = (i - 1) * maxS;
           }
       }
       if (fl) {
           for (int i = 0; i < tmp; ++i) {
               ans = max(ans, q + a[i] + pref[tmp]);
           }
       }

       cout << ans << endl;
    }
    cout.flush();
    return 0;
}