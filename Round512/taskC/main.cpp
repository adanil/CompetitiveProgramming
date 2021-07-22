#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<short> ticket(n);
    ll maxWin = 0;
    for (int i = 0;i < n;i++) {
        char c;
        cin >> c;
        short el = c - '0';
        ticket[i] = el;
        maxWin += el;
    }
    if (maxWin == 0){
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0;i < maxWin;i++){
        ll currSum = 0;
        bool fl = true;
        for (int j = 0;j < n;j++){
            if (currSum == i)
                currSum = 0;
            if (currSum > i){
                break;
                fl = false;
            }
            currSum += ticket[j];

        }
        if (currSum != i && currSum != 0)
            fl = false;
        if (fl){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}