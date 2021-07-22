#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string>

using namespace std;
using ll = long long;


ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ll>a(n);
    ll prev;
    int k = 0;
    vector<ll>ans;
    for (int i = 0;i < n;i++){
        cin >> a[i];
        if (i == 0) {
            prev = a[i];
            ans.push_back(a[i]);
        }
        else{
            if (gcd(a[i],prev) != 1){
                k++;
                ans.push_back(1);
            }
            prev = a[i];
            ans.push_back(a[i]);
        }
    }
    cout << k << endl;
    for (auto el : ans)
        cout << el << ' ';

    return 0;
}