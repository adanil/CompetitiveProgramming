#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,x;
        cin >> n >> x;
        vector<ll>a(n),b(n);

        for (int i = 0;i < n;i++){
            cin >> a[i];
        }
        for (int i = 0;i < n;i++){
            cin >> b[i];
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        bool fl = true;
        for (int i = 0;i < n;i++){
            if (a[i] + b[i] > x){
                fl = false;
                break;
            }
        }
        if (fl)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }

    return 0;
}