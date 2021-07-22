#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int w,h,n;
        cin >> w >> h >> n;
        int k = 1;
        int ans = 1;
        while (w % 2 == 0){
            ans += k;
            w /= 2;
            k *= 2;
        }
        while (h % 2 == 0){
            ans += k;
            h /= 2;
            k *= 2;
        }


        if (ans >= n )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}