#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>ans(n,1);
        for (auto &el : ans)
            cout << el << ' ';
        cout << endl;
    }
    return 0;
}