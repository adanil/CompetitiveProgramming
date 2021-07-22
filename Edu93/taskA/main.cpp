#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<ll,ll>>a;
        for (int i = 0;i < n;i++){
            ll el;
            cin >> el;
            a.push_back({i,el});
        }
        sort(a.begin(),a.end());
        if (a[0].second + a[1].second <= a[n - 1].second)
            cout << a[0].first + 1 << ' ' << a[1].first + 1 << ' ' << a[n-1].first + 1 << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}