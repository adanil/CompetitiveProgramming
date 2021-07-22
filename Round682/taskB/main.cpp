#include <iostream>
#include <vector>
#include <algorithm>

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
        vector<ll>b(n);
        for (auto &el : b)
            cin >> el;
        bool ans = false;
        for (int i = 0;i < n;i++){
            for (int j = i + 1;j < n;j++)
                if (b[i] == b[j]){
                    ans = true;
                    break;
                }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}