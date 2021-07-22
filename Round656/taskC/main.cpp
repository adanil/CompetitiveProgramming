#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

bool isSorted(vector<ll> &a){
    for (int i = 1;i < a.size();i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>a(n);
        bool voz = false;
        bool ub = false;
        bool fl = false;
        for (auto &el : a){
            cin >> el;
        }
        ll ans = 0;
        int i = n -1;
        if (n != 1 && !isSorted(a)) {
           while (a[i - 1] >= a[i] && i >= 1)i--;
           while (a[i] >= a[i - 1] && i >= 1)i--;
           ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}