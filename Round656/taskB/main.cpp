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
        int n;
        cin >> n;
        set<ll>check;
        for (int i = 0;i < n * 2;i++){
            ll el;
            cin >> el;
            if (check.count(el) == 0){
                cout << el << ' ';
                check.insert(el);
            }
        }
        cout << endl;
    }
    return 0;
}