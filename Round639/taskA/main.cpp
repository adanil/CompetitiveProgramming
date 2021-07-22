#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;


int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,m;
        cin >> n >> m;
        if (n == 1){
            cout << "YES" << endl;
        }
        else{
            if (m <= 2 && n <= 2)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}