#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;
using ll = long long;


int main() {
    ll t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll>a(n);
        bool fl = true;
        ll mx = -1;
        ll indmx = 0;
        for (int i = 0;i < n;i++){
            cin >> a[i];
            if (i != 0) {
                if (a[i] != a[i - 1])
                    fl = false;
            }
            if (a[i] >= mx) {
                mx = a[i];
                indmx = i;
            }
        }
        if (fl)
            cout << -1 << endl;
        else{
            if (indmx < n - 1){
                cout << indmx + 1 << endl;
            }
            else{
                while(a[indmx] == a[indmx - 1]){
                    indmx--;
                }
                cout << indmx + 1 << endl;
            }
        }
    }
    return 0;
}