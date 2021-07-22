#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;
       string s;
       cin >> s;
       ll ans = 0;
       bool fl = false;
       char need = 'q';
       int cntrOne = 0,cntrZeros = 0;
       for (int i = 1;i < n;i++){
           if (s[i] == s[i - 1]){
               if (s[i] == '1')
                   cntrOne++;
               else
                   cntrZeros++;
           }
       }
       ans = max(cntrOne,cntrZeros);
       cout << ans << endl;
    }
    return 0;
}