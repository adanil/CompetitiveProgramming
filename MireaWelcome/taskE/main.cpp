#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll n;
    cin >> n;
//for (ll q = -10000;q < 1000;q++) {
//    n = q;
    ll startN = n;
    string gAns;

    if (n >= 0) {
        if (n == 0) {
            cout << 0 << endl;
//            break;
        }
        int cntr = 42;
        ull copyn = n;
        string ans;
        int bit = 0;
        while (cntr) {
            if (bit % 2 != 0) {
                if ((copyn & ((ull)1 << bit)) != 0)
                    copyn += (ull)1 << (bit + 1);
            }
            bit++;
            cntr--;
        }
        while (copyn > 0) {
            if ((copyn & 1) != 0)
                ans += '1';
            else
                ans += '0';
            copyn >>= 1;

        }
//        gAns = ans;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

    } else {
//        cout << ((ull)1 << 31) << endl;
        int cntr = 42;
        n = abs(n);
        ull copyn = n;
        string ans;
        int bit = 0;
        while (cntr) {
            if (bit % 2 == 0) {
                if ((copyn & ((ull)1 << bit)) != 0)
                    copyn += (ull)1 << (bit + 1);
            }
            bit++;
            cntr--;
        }
        while (copyn > 0) {
            if ((copyn & 1) != 0)
                ans += '1';
            else
                ans += '0';
            copyn >>= 1;

        }
//        gAns = ans;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;

    }
    ll test = 0;
    for (int i = 0;i < gAns.size();i++){
        if (gAns[i] == '1')
            test += pow(-2,i);
    }
//    if (test == startN) {
////        cout << "OK" << endl;
//    }
//    else {
//        cout << "WRONG: " << startN << ' ' << test << endl;
//        cout << gAns << endl;
//        return 0;
//    }

//}
    return 0;
}