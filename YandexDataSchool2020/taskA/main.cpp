#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include <iostream>
#include <map>


using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<ll,ll> freq;
    ll n;
    cin >> n;
    for (ll i = 0;i < n;i++){
        ll el;
        cin >> el;
        ++freq[el];
    }
    ll maxValue = freq.begin()->first;
    ll maxFreq = freq.begin()->second;
    for (auto it : freq){
        if (it.second >= maxFreq){
            maxFreq = it.second;
            maxValue = it.first;
        }
    }
    cout << maxValue << endl;
    return 0;
}