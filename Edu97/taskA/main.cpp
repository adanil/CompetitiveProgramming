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
        int l,r;
        cin >> l >> r;
        int cnt = r - l + 1;
        int maxa = r + 1;
        int mina = l - 1;
        if ( mina * 2 <= r && l < ((maxa + 1)/2)){
            cout << "NO" << endl;
        } else
            cout << "YES" << endl;
    }
    return 0;
}