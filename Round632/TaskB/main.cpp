#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n);
        for (ll i = 0;i < n;i++)
            cin >> a[i];
        for (ll i = 0;i < n;i++)
            cin >> b[i];

        bool havePl = false;
        bool haveMn = false;

        bool flNo = false;

        for (int i = 0;i < n;i++){
            if (b[i] > a[i])
                if (!havePl){
                    cout << "NO" << endl;
                    flNo = true;
                    break;
                }
            if (b[i] < a[i])
                if (!haveMn){
                    cout << "NO" << endl;
                    flNo = true;
                    break;
                }
            if (a[i] == 1)
                havePl = true;
            if (a[i] == -1)
                haveMn = true;
        }
        if (!flNo)
            cout << "YES" << endl;

    }



    return 0;
}