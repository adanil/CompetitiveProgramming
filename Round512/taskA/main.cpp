#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    bool fl = false;
    for (int i = 0;i < n;i++){
        ll el;
        cin >> el;
        if (el == 1)
            fl = true;
    }
    if (fl)
        cout << "HARD" << endl;
    else
        cout << "EASY" << endl;
    return 0;
}