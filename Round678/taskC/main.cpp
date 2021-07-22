#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>

using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<short>sign; // 1 - > // -1 - <

bool binSearch(int n,int pos){
    int left = 0;
    int right = n;
    while (left < right){
        int middle = (left + right)/2;
        if (middle == pos){
            left = middle + 1;
            continue;
        }
        else if (middle < pos) {
            sign[middle] = -1;
            left = middle + 1;
        }
        else{
            sign[middle] = 1;
            right = middle;
        }
    }
}


int main() {
    int n,x,pos;
    cin >> n >> x >> pos;
    sign.resize(n + 1);
    binSearch(n,pos);
    ll modulo = 1e9 + 7;
    ll ans = 1;
    ll bigger = n - x;
    ll lesses = x - 1;
    ll cnt = 0;

    for (auto el : sign) {
        if (el == 1){
            ans *= bigger;
            ans %= modulo;
            bigger--;
            cnt++;
        }
        else if (el == -1){
            ans *= lesses;
            ans %= modulo;
            lesses--;
            cnt++;
        }
//        cout << el << ' ';
    }
    ll ost = n - cnt - 1;
    ll fac = 1;
    for (int i = 1;i <= ost;i++){
        fac *= i;
        fac %= modulo;
    }
    ans *= fac;
    ans %= modulo;
    cout << ans << endl;

    return 0;
}