#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll x,y,z;
        cin >> x >> y >> z;
        if (y == z && x > y){
            cout << "NO" << endl;
        }
        else if (x != y && y != z && x != z){
            cout << "NO" << endl;
        }
        else if (x == y && z <= x){
            cout << "YES" << endl;
            cout << x << ' ' << z << ' ' << z << endl;
        }
        else if (x == z && y <= x){
            cout << "YES" << endl;
            cout << x << ' ' << y << ' ' << y << endl;
        }
        else if (y == z && x <= y){
            cout << "YES" << endl;
            cout << y << ' ' << x << ' ' << x << endl;
        }
        else
            cout << "NO" << endl;

    }
    return 0;
}