#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>b(n);
    for (auto &el: a)
        cin >> el;
    for (auto &el: b)
        cin >> el;

    ll sum1 = 0;
    ll sum2 = 0;

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());

    ll m1 = a[0];
    ll m2 = b[0];

    ll aInd = 0;
    ll bInd = 0;

    bool aEmpt = false;
    bool bEmpt = false;

    for (int i = 0;i < n;i++){

        if (aEmpt){
            bInd++;
            if (bInd >= b.size())
                bEmpt = true;
            else
                m2 = b[bInd];
        }
        else if (bEmpt){
            sum1 += m1;
            aInd++;
            if (aInd >= a.size())
                aEmpt = true;
            else
                m1 = a[aInd];
        }
        else {
            if (m1 >= m2) {
                sum1 += m1;
                aInd++;
                if (aInd >= a.size())
                    aEmpt = true;
                else
                    m1 = a[aInd];
            } else {
                bInd++;
                if (bInd >= b.size())
                    bEmpt = true;
                else
                    m2 = b[bInd];
            }
        }


        if (bEmpt){
            aInd++;
            if (aInd >= a.size())
                aEmpt = true;
            else
                m1 = a[aInd];
        }
        else if (aEmpt){
            sum2 += m2;
            bInd++;
            if (bInd >= b.size())
                bEmpt = true;
            else
                m2 = b[bInd];
        }
        else {
            if (m2 >= m1) {
                sum2 += m2;
                bInd++;
                if (bInd >= b.size())
                    bEmpt = true;
                else
                    m2 = b[bInd];
            } else {
                aInd++;
                if (aInd >= a.size())
                    aEmpt = true;
                else
                    m1 = a[aInd];
            }
        }
    }

    cout << sum1 - sum2 << endl;
    return 0;
}