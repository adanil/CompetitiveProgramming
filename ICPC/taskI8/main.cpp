#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<bool>d(1827);
    for (int i = 0;i < n;i++){
        int a,b;
        cin >> a >> b;
        for (;a <= b;a++)
            d[a] = true;
    }

    bool globalFl = false;
    for (int i = 1;i <= 1826 - 90;i++){
        int s = 0;
        for (int j = 0;j < min(180,1826 - i);j++) {
            if (d[i + j])
                s++;
        }
//        cout << s << endl;
        if (s > 90) {
            globalFl = true;
            cout << "No" << endl;
            break;
        }
    }
    if (!globalFl)
        cout << "Yes" << endl;
    return 0;
}