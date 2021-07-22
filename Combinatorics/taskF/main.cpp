#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


ll sum(ll n){
    return (n*(n + 1))/2;
}

int main() {
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<ll>p;
    ll l = 0;
    ll prev = -10000000000;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
        if (a[i] == prev || prev == -10000000000){
            l++;
        }
        else{
            p.push_back(l);
            l = 1;

        }
        prev = a[i];
    }
    p.push_back(l);
    ll ans = 0;
    for (auto el : p){
        ans += sum(el);
    }
    cout << ans << endl;
    return 0;
}