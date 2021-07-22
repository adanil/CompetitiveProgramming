#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll>unlocked;
        vector<ll>a(n);
        for (int i = 0;i < n;i++)
            cin >> a[i];
        vector<int>lock(n);
        for (int i = 0;i < n;i++) {
            cin >> lock[i];
            if (lock[i] == 0)
                unlocked.push_back(a[i]);
        }
        sort(unlocked.begin(),unlocked.end());
        int j = unlocked.size() - 1;
        for (int i = 0;i < n;i++){
            if (lock[i] == 0) {
                cout << unlocked[j] << ' ';
                j--;
            } else
                cout << a[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}