#include <iostream>

using namespace std;
using ll = long long;

int sign(ll n){
    return n > 0 ?1:-1;
}

int main() {
    int n;
    cin >> n;
    ll a,b;
    ll l = 1,r = n/2;
    cout << "? " << l << endl;
    fflush(stdout);
    cin >> a;
    cout << "? " << r+1 << endl;
    fflush(stdout);
    cin >> b;
    int sn = sign(a-b);
    ll cnt = 2;
    ll mid = n/4;
    if (a == b){
        cout << "! " << 1 << endl;
        fflush(stdout);
        return 0;
    }
    while(cnt < 60) {
        mid = (l + r)/2;
        cout << "? " << mid << endl;
        fflush(stdout);
        cin >> a;
        cout << "? " << mid + n/2 << endl;
        fflush(stdout);
        cin >> b;
        cnt += 2;
        ll f;
        f = a - b;
        if (f % 2 != 0) {
            cout << "! -1" << endl;
            fflush(stdout);
            return 0;
        } else {
            if (f == 0) {
                cout << "! " << mid << endl;
                fflush(stdout);
                return 0;
            } else if (sign(f) == sn) {
                l = mid+1;
            }
            else{
               r = mid-1;
            }
        }
    }
    cout << "! -1" << endl;
    fflush(stdout);
    return 0;
}