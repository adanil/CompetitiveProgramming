#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

bool check(ll a){
    ll cpa = a;
    ll sum = 0;
    while (a > 0){
        sum += a % 10;
        a /= 10;
    }
    if (cpa % sum == 0)
        return true;
    else return false;
}

int main() {
    ll a,b;
    cin >> a >> b;
    vector<ll>ans;
    for (ll i = a;i <= b;i++){
        if (check(i))
            ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    for (auto q : ans)
        cout << q << ' ';
    return 0;
}