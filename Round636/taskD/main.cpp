#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<ll>a(n);
        for (ll i = 0;i < n;i++){
            cin >> a[i];
        }
        vector<ll> sums(n/2);
        vector<ll>leftBord(n/2);
        vector<ll>rightBord(n/2);
        map<ll,ll> mp;
        for (int i = 0;i < n/2;i++){
            ll l,r;
            l = a[i];r = a[n-1-i];
            sums[i] = l + r;
            ++mp[sums[i]];
            leftBord[i] = min(l,r) + 1;
            rightBord[i] = max(l,r) + k;
        }
        ll resLeftBord = *max_element(leftBord.begin(),leftBord.end());
        ll resRightBord = *min_element(rightBord.begin(),rightBord.end());

        ll maxCntSumsOne = 0;
        ll maxCntSumsTwo = 0;
        ll maxSumTwo = 0;
        for (auto el : mp){
            if (el.first >= resLeftBord && el.first <= resRightBord)
                if (el.second > maxCntSumsOne)
                    maxCntSumsOne = el.second;
            if (el.second > maxCntSumsTwo) {
                maxCntSumsTwo = el.second;
                maxSumTwo = el.first;
            }
        }
        ll ansOne =  n/2 - maxCntSumsOne;
        ll ansTwo = 0;
        for (int i = 0;i < n/2;i++){
            if (sums[i] == maxSumTwo)
                continue;
            if (maxSumTwo >= leftBord[i] && maxSumTwo <= rightBord[i])
                ansTwo++;
            else
                ansTwo += 2;
        }
        cout << min(ansOne,ansTwo) << endl;
    }
    return 0;
}