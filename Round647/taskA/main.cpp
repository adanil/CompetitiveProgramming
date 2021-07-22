#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll a,b;
        cin >> a >> b;
        ll ans = 0;
        if (b > a){
            while (a < b){
//                cout << a << endl;
                a = a << 1;
                ans++;
            }
            if (a == b) {
//                cout << "ANS: " << ans << endl;
                ll realAns = 0;
                realAns += (ans / 3);
                ans -= (ans / 3) * 3;
                realAns += ans / 2;
                ans -= (ans / 2) * 2;
                realAns += ans;
                cout << realAns << endl;
            }
            else
                cout << -1 << endl;
        }
        else{
            while(b < a){
//                cout << a << endl;
                if (a & 1 != 0)
                    break;
                a = a >> 1;
                ans++;
            }
            if (a == b) {
//                cout << "ANS: " << ans << endl;
                ll realAns = 0;
                realAns += (ans / 3);
                ans -= (ans / 3) * 3;
                realAns += ans / 2;
                ans -= (ans / 2) * 2;
                realAns += ans;
                cout << realAns << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}