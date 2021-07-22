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
        int n;
        cin >> n;
        int ones = 0,tw = 0;
        int el;
        for (int i = 0;i < n;i++) {
            cin >> el;
            if (el == 1)
                ones++;
            else
                tw++;
        }
        if ((ones + tw*2) % 2 == 0 ){
            if (((ones + tw*2) / 2) % 2 != 0 && ones == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }

//        else if (tw == 0 && ones % 2 == 0)
//            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}