#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    ll a,b,c;
    if ((n - 2) % 3 == 0){
        a = 2; b = 1; c = n - 3;
    }
    else{
        a = 1;b = 1;c = n - 2;
    }
    cout << a << ' ' << b << " " <<  c << endl;
    return 0;
}