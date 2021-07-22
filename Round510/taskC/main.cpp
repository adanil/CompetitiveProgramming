#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using ll = long long;

struct el{
    ll value;
    ll id;

    bool operator<(const el& a)const{
        return this->value > a.value;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    multiset<el>a;
    ll countMinus = 0;
    ll minNeg = 0;
    ll minNegId = 0;
    bool haveZero = false;
    ll countZero = 0;
    ll zeroId = 0;
    bool allZero = false;
    vector<ll>zeroInd;
    for (int i = 0;i < n;i++){
        el e;
        cin >> e.value;
        e.id = i;
        if (e.value == 0) {
            haveZero = true;
            zeroId = i;
            countZero++;
            zeroInd.push_back(i);
            continue;
        }
        a.insert(e);

        if (e.value < 0) {
            countMinus++;
            if (minNeg == 0) {
                minNeg = e.value;
                minNegId = i;
            }
            else if (abs(minNeg) > abs(e.value)) {
                minNeg = e.value;
                minNegId = i;
            }
        }
    }
//    cout << a.size() << endl;
    if (a.empty())
        allZero = true;

    if ( haveZero && countMinus % 2 != 0){
        ll sec = 0;
        ll my = minNegId;
        while(sec != zeroInd.size()){
            cout << 1 << ' ' << zeroInd[sec] + 1 << ' ' << my + 1 << endl;
            sec++;
        }
        if (a.size() == 1)
            return 0;
        cout << 2 << ' ' << my + 1 << endl;

        for (auto it = a.begin(); it != a.end(); it++) {
            if (it->id == minNegId) {
                a.erase(it);
                break;
            }
        }

    }
    else {

        if (countMinus % 2 != 0) {
            if (a.size() == 1)
                allZero = true;
            cout << 2 << ' ' << minNegId + 1 << endl;
            for (auto it = a.begin(); it != a.end(); it++) {
                if (it->id == minNegId) {
                    a.erase(it);
                    break;
                }
            }

        }
        if (allZero) {
            ll sec = 1;
            ll my = 0;
            while (sec != zeroInd.size()) {
                cout << 1 << ' ' << zeroInd[sec] + 1 << ' ' << zeroInd[my] + 1 << endl;
                sec++;
            }
            return 0;
        } else if (haveZero) {
            ll sec = 1;
            ll my = 0;
            while (sec != zeroInd.size()) {
                cout << 1 << ' ' << zeroInd[sec] + 1 << ' ' << zeroInd[my] + 1 << endl;
                sec++;
            }
            cout << 2 << ' ' << zeroInd[my] + 1 << endl;
//        for (auto it = a.begin();it != a.end();it++){
//            if (it->id == zeroId){
//                a.erase(it);
//                break;
//            }
//        }
        }
    }



    auto it = a.begin();
    ll ans = it->value;
    while(a.size() > 1) {
        auto itSec = ++a.begin();
        ans *= itSec->value;
        cout << 1 << ' ' << itSec->id + 1 << ' ' << it->id + 1 << endl;
        a.erase(itSec);
    }
//    cout << ans << endl;






    return 0;
}