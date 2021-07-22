#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
using ll = long long;

ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm (ll a, ll b) {
    return a / gcd (a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll l,r;
        cin >> l >> r;
        ll x = -1,y = -1;
        for (ll i = r;i >= l;i--){
            if (i % 2 == 0 && i / 2 < l){
                break;
            }
            else if (i % 2 == 0){
                x = i/2;
                int c = 1;
                while (i % c != 0 ){
                    if (i / c < l)
                        break;
                    c++;
                    if (c == 2)
                        c++;
                }
                if (i / c >= l) {
                    y = i / c;
                    break;
                }
            }
        }
        if (x == -1 || y == -1){
            cout << -1 << ' ' << -1 << '\n';
        }
        else
            cout << x << ' ' << y << '\n';
    }
    cout.flush();
    return 0;
}