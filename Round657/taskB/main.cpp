#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while(t--){
        ll l,r,m;
        cin >> l >> r >> m;
        if (m >= l) {
            for (ll i = l; i <= r; i++) {
                ll ost = m % i;
                if (ost <= r - l) {
                    ll b = r;
                    ll c = b - ost;
                    while (c < l) {
                        b--;
                        c++;
                    }
                    cout << i << ' ' << b << ' ' << c << endl;
                    break;
                }

                else if (i - ost <= r - l){
                    ost = i - ost;
                    if (abs(ost) <= r - l) {
                        ll b = r;
                        ll c = b - ost;
                        while (c < l) {
                            b--;
                            c++;
                        }
                        cout << i << ' ' << c << ' ' << b << endl;
                        break;
                    }
                }
            }
        }
        else{
            for (ll i = l; i <= r; i++) {
                ll ost = m % i;
                ost = i - ost;
                if (abs(ost) <= r - l) {
                    ll b = r;
                    ll c = b - ost;
                    while (c < l) {
                        b--;
                        c++;
                    }
                    cout << i << ' ' << c << ' ' << b << endl;
                    break;
                }
            }
        }
    }
    return 0;
}